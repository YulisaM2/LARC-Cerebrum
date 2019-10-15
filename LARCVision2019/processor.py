import cv2
import numpy as np
import math
from networktables import NetworkTablesInstance
from networktables import NetworkTables

ninst = NetworkTablesInstance.getDefault()
ninst.startClient("localhost")

threshTable = ninst.getTable("ThreshTable")


class Processor:

    def __init__(self):
        self.thresholdRed = [np.array([0, 120, 70]), np.array([10, 255, 255]), np.array([170, 120, 70]),
                             np.array([180, 255, 255])]
        self.thresholdGreen = [np.array([30, 100, 30]), np.array([90, 255, 255])]
        self.thresholdBlue = [np.array([90, 0, 40]), np.array([140, 255, 255])]

        threshTable.putNumber("low_h", self.thresholdBlue[0][0])
        threshTable.putNumber("low_s", self.thresholdBlue[0][1])
        threshTable.putNumber("low_v", self.thresholdBlue[0][2])

        threshTable.putNumber("up_h", self.thresholdBlue[1][0])
        threshTable.putNumber("up_s", self.thresholdBlue[1][1])
        threshTable.putNumber("up_v", self.thresholdBlue[1][2])

        self.percentageColorArea = 20
        self.percentageArea = 3
        self.percentageWidth = 5

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
        width = 100
        height = 100
        destinationPoints = coordList.copy()

        # topleft, topRight, bottomLeft, bottomRight
        destinationPoints[0] = (0, 0)
        destinationPoints[1] = (width, 0)
        destinationPoints[2] = (0, height)
        destinationPoints[3] = (width, height)

        m = cv2.getPerspectiveTransform(coordList, destinationPoints)
        warped = cv2.warpPerspective(img, m, (width, height), flags=cv2.INTER_LINEAR)

        return warped

    def colorConcentration(self, img):
        area = img.shape[0] * img.shape[1]
        if area <= 0:
            return False

        contours, _ = cv2.findContours(img, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
        currArea = 0
        for contour in contours:
            currArea += cv2.contourArea(contour)

        areaPercent = currArea / area * 100
        return areaPercent >= self.percentageColorArea

    def getColorPosition(self, img, token, stacks):
        height = img.shape[0]
        width = img.shape[1]
        segmentHeight = math.floor(height / 4)

        segmentWidth = math.floor(width / 4)
        segmentLeft = img[0:height, 0:segmentWidth]
        segmentRight = img[0:height, width - segmentWidth: width]

        currPos = 0

        for j in range(0, len(stacks[0])):
            currSegment = segmentLeft[currPos:currPos + segmentHeight, 0:segmentWidth]
            currPos += segmentHeight
            stacks[0][j] = token if self.colorConcentration(currSegment) else stacks[0][j]

        currPos = 0
        for j in range(0, len(stacks[1])):
            currSegment = segmentRight[currPos:currPos + segmentHeight, 0:segmentWidth]
            currPos += segmentHeight
            stacks[1][j] = token if self.colorConcentration(currSegment) else stacks[1][j]

        return stacks

    def process(self, img):
        newImg = img.copy()
        newImg = cv2.blur(newImg, (5, 5))
        stacks = [["r", "r", "r", "r"], ["r", "r", "r", "r"]]

        newImg = cv2.cvtColor(newImg, cv2.COLOR_BGR2HSV)

        self.thresholdBlue[0][0] = threshTable.getNumber("low_h", self.thresholdBlue[0][0])
        self.thresholdBlue[0][1] = threshTable.getNumber("low_s", self.thresholdBlue[0][1])
        self.thresholdBlue[0][2] = threshTable.getNumber("low_v", self.thresholdBlue[0][2])

        self.thresholdBlue[1][0] = threshTable.getNumber("up_h", self.thresholdBlue[1][0])
        self.thresholdBlue[1][1] = threshTable.getNumber("up_s", self.thresholdBlue[1][1])
        self.thresholdBlue[1][2] = threshTable.getNumber("up_v", self.thresholdBlue[1][2])

        heightOffset = 35
        widthOffset = 53
        thresholdArea = newImg.copy()[heightOffset:newImg.shape[0], widthOffset:newImg.shape[1]]

        cv2.imshow("TH AREA", thresholdArea)

        # Range for lower red
        maskLowerRed = cv2.inRange(thresholdArea, self.thresholdRed[0], self.thresholdRed[1])

        # Range for upper range
        maskUpperRed = cv2.inRange(thresholdArea, self.thresholdRed[2], self.thresholdRed[3])

        # Generating the final mask to detect red color
        maskRed = maskLowerRed + maskUpperRed

        # cv2.imshow('Rojo', maskRed)

        # Adding green mask
        maskGreen = cv2.inRange(thresholdArea, self.thresholdGreen[0], self.thresholdGreen[1])
        # cv2.imshow('Verde', maskGreen)

        # Adding blue mask
        maskBlue = cv2.inRange(thresholdArea, self.thresholdBlue[0], self.thresholdBlue[1])
        # cv2.imshow("Azul", maskBlue)

        maskFinal = maskBlue + maskGreen + maskRed

        contours, _ = cv2.findContours(maskFinal, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
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

            # Filter unnecessary areas such as stacks that are behind and the floor's lines
            if area / (newImg.shape[0] * newImg.shape[1]) * 100 > self.percentageArea and width / img.shape[
                1] * 100 > self.percentageWidth:

                pointsToAdd = np.vstack(contour).squeeze().tolist()
                for i in range(0, len(pointsToAdd)):
                    pointsToAdd[i][0] = pointsToAdd[i][0] + widthOffset
                    pointsToAdd[i][1] = pointsToAdd[i][1] + heightOffset
                    # print(pointsToAdd[i])

                cv2.drawContours(newImg, np.array([pointsToAdd]), 0, (0, 255, 0), 2)
                rodPoints.extend(pointsToAdd)

        unwarped = np.zeros(shape=[img.shape[0], img.shape[1], 3], dtype=np.uint8)

        if len(rodPoints) > 0:
            topLeft = self.getClosestTo(rodPoints, (0, 0))
            bottomLeft = self.getClosestTo(rodPoints, (0, newImg.shape[0]))
            topRight = self.getClosestTo(rodPoints, (newImg.shape[1], 0))
            bottomRight = self.getClosestTo(rodPoints, (newImg.shape[1], newImg.shape[0]))

            wrappedPoints = np.float32([topLeft, topRight, bottomLeft, bottomRight])

            unwarped = self.unwarpRods(img, wrappedPoints)

            unwarpedGreenMask = self.unwarpRods(maskGreen, wrappedPoints)
            unwarpedBlueMask = self.unwarpRods(maskBlue, wrappedPoints)
            unwarpedRedMask = self.unwarpRods(maskRed, wrappedPoints)

            blueRods = self.getColorPosition(unwarpedBlueMask, "b", stacks)

            greenRods = self.getColorPosition(unwarpedGreenMask, "g", stacks)

            redRods = self.getColorPosition(unwarpedRedMask, "r", stacks)

        return stacks, newImg
