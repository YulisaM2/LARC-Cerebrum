import cv2
import numpy as np
import math


class Processor:

    def __init__(self):
        self.height = 720
        self.width = 1280
        self.farRight = [35, 150, 124, 178]
        self.closeRight = [1, 200, 200, 324]
        self.farLeft = [55, 100, 55, 100]
        self.closeLeft = [55, 100, 55, 100]
        self.thresholdRed = [np.array([0, 120, 70]), np.array([10, 255, 255]), np.array([170, 120, 70]),
                             np.array([180, 255, 255])]
        self.thresholdGreen = [np.array([60, 30, 0]), np.array([90, 255, 255])]
        self.thresholdBlue = [np.array([90, 0, 0]), np.array([120, 190, 120])]
        self.percentage = 20

    def getDistance(self, coordA, coordB):
        return math.sqrt((coordA[0] - coordB[0]) ** 2 + (coordA[1] - coordB[1]) ** 2)

    def getClosestTo(self, coordList, targetCoord):
        closest = []
        minDistance = 100000
        currDistance = 0
        for point in coordList:
            currDistance = self.getDistance(point, targetCoord)
            if currDistance < minDistance:
                minDistance = currDistance
                closest = point
        return closest

    def unwarpRods(self, img, coordList):
        # height, width = img.shape[:2]
        width = 400
        height = 300
        destinationPoints = coordList.copy()

        # topleft, topRight, bottomLeft, bottomRight
        destinationPoints[0] = (0,0)
        destinationPoints[1] = (width, 0)
        destinationPoints[2] = (0, height)
        destinationPoints[3] = (width,height)
        # print("Coordlist")
        # print(coordList)
        # print("Destinantion Points")
        # print(destinationPoints)

        m = cv2.getPerspectiveTransform(coordList, destinationPoints)
        warped = cv2.warpPerspective(img, m, (width,height), flags=cv2.INTER_LINEAR)

        cv2.imshow("WARPEDDD", warped)

    def colorConcentration(self, img):
        area = img.shape[0] * img.shape[1]
        contours, hierarchy = cv2.findContours(img, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
        currArea = 0
        for contour in contours:
            currArea += cv2.contourArea(contour)

        areaPercent = currArea / area * 100
        return areaPercent >= self.percentage

    def getColorPosition(self, img):
        height = img.shape[0]
        width = img.shape[1]
        segmentHeight = math.floor(height / 4)

        currPos = 0
        rods = [0, 0, 0, 0]
        for i in range(0, len(rods)):
            currSegment = img[currPos:currPos + segmentHeight, 0:width]
            currPos += segmentHeight
            rods[i] = 1 if self.colorConcentration(currSegment) else 0

        return rods

    def processLeft(self, img):
        newImg = img.copy()

        farSection = newImg[self.farLeft[0]:self.farLeft[1], self.farLeft[2]:self.farLeft[3]]
        closeSection = newImg[self.closeLeft[0]:self.closeLeft[1], self.closeLeft[2]:self.closeLeft[3]]

    def processRight(self, img):
        newImg = img.copy()
        # newImg = cv2.blur(newImg, (5, 5))
        # cv2.imshow('test', newImg)

        newImg = cv2.cvtColor(newImg, cv2.COLOR_BGR2HSV)
        farSection = newImg[self.farRight[0]:self.farRight[1], self.farRight[2]:self.farRight[3]]
        closeSection = newImg[self.closeRight[0]:self.closeRight[1], self.closeRight[2]: self.closeRight[3]]

        # cv2.imshow('far', farSection)
        # cv2.imshow('close', closeSection)

        # Range for lower red
        maskLowerRed = cv2.inRange(newImg, self.thresholdRed[0], self.thresholdRed[1])

        # Range for upper range
        maskUpperRed = cv2.inRange(newImg, self.thresholdRed[2], self.thresholdRed[3])

        # Generating the final mask to detect red color
        maskRed = maskLowerRed + maskUpperRed

        cv2.imshow('Rojo', maskRed)

        # Adding green mask
        maskGreen = cv2.inRange(newImg, self.thresholdGreen[0], self.thresholdGreen[1])
        cv2.imshow('Verde', maskGreen)

        # Adding blue mask
        maskBlue = cv2.inRange(newImg, self.thresholdBlue[0], self.thresholdBlue[1])
        cv2.imshow("Azul", maskBlue)

        maskFinal = maskBlue + maskGreen + maskRed

        contours, hierarchy = cv2.findContours(maskFinal, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        newImg = cv2.cvtColor(newImg, cv2.COLOR_HSV2BGR)

        rodPoints = []
        for contour in contours:
            area = cv2.contourArea(contour)
            rect = cv2.minAreaRect(contour)
            box = cv2.boxPoints(rect)
            box = np.int0(box)

            minX = min(box, key=lambda x: x[0])[0]
            maxX = max(box, key=lambda x: x[0])[0]
            width = maxX - minX

            if area > 800 and width > 50:
                # cv2.drawContours(newImg, [box], 0, (0, 255, 0), 2)
                rodPoints.extend(box.tolist())

        cv2.imshow("Mask Final", maskFinal)
        cv2.imshow("New Image", newImg)

        topLeft = self.getClosestTo(rodPoints, (0, 0))
        bottomLeft = self.getClosestTo(rodPoints, (0, newImg.shape[0]))
        topRight = self.getClosestTo(rodPoints, (newImg.shape[1], 0))
        bottomRight = self.getClosestTo(rodPoints, (newImg.shape[1], newImg.shape[0]))

        wrappedPoints = np.float32([topLeft, topRight, bottomLeft, bottomRight])

        self.unwarpRods(newImg, wrappedPoints)


        stacks = ["", "", "", ""]

        blueRods = self.getColorPosition(maskBlue)
        print(blueRods)

        for i in range(0, 4):
            if blueRods[i] == 1:
                stacks[i] = "blue"

        greenRods = self.getColorPosition(maskGreen)
        print(greenRods)

        for i in range(0, 4):
            if greenRods[i] == 1:
                stacks[i] = "green"

        redRods = self.getColorPosition(maskRed)
        print(redRods)

        for i in range(0, 4):
            if redRods[i] == 1:
                stacks[i] = "red"

        for stack in stacks:
            print(stack)
