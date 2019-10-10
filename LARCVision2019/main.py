import cv2
import numpy as np
import processor

processing = processor.Processor()

# cv2.imshow('Test', cap)
# cv2.waitKey(0)
# cap = cv2.VideoCapture(700)
# while True:
    # ret, img = cap.read()
    # if ret:
    #     cv2.imshow(img)
cap = cv2.imread('SS LARC/WIN_20190920_12_08_51_Pro.jpg')
cap2 = cv2.imread('SS LARC/WIN_20190920_12_07_48_Pro.jpg')
cap3 = cv2.imread('SS LARC/WIN_20190920_12_07_41_Pro.jpg')
processing.processRight(cap)
cv2.waitKey(0)
processing.processRight(cap2)
cv2.waitKey(0)
processing.processRight(cap3)
cv2.waitKey(0)

