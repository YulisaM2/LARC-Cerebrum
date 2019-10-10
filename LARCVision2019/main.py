import cv2
import numpy as np
import processor

processing = processor.Processor()


# cv2.imshow('Test', cap)
# cv2.waitKey(0)
cap = cv2.VideoCapture(1)
while True:
    ret, img = cap.read()
    if ret:
        cv2.imshow(img)
    cv2.waitKey(1)

# cap = cv2.imread('SS LARC/WIN_20190920_12_08_51_Pro.jpg')
# cap2 = cv2.imread('SS LARC/WIN_20190920_12_07_48_Pro.jpg')
# cap3 = cv2.imread('SS LARC/WIN_20190920_12_07_41_Pro.jpg')

# cap = cv2.imread('SS LARC/left1.jpg')
# cap2 = cv2.imread('SS LARC/left2.jpg')
# cap3 = cv2.imread('SS LARC/left3.jpg')

processing.process(cap)
cv2.waitKey(0)
processing.process(cap2)
cv2.waitKey(0)
processing.process(cap3)
cv2.waitKey(0)

