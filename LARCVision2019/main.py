from cscore import CameraServer
import cv2
import numpy as np
import processor
import serial_comms
import time

cs = CameraServer.getInstance()
cs.enableLogging()

# Capture from the first USB Camera on the system
cameraLeft = cs.startAutomaticCapture(name="CameraLeft", path="/dev/v4l/by-path/platform-3f980000.usb-usb-0:1.2:1.0-video-index0")
cameraRight = cs.startAutomaticCapture(name="CameraRight", path="/dev/v4l/by-path/platform-3f980000.usb-usb-0:1.3:1.0-video-index0")
cameraRight.setResolution(320, 240)
cameraRight.setFPS(30)

cameraLeft.setResolution(320, 240)
cameraLeft.setFPS(30)
# Get a CvSink. This will capture images from the camera
cameraRightSink = cs.getVideo(camera=cameraRight)
cameraLeftSink = cs.getVideo(camera=cameraLeft)

# (optional) Setup a CvSource. This will send images back to the Dashboard
outputStream = cs.putVideo("Name", 320, 240)
maskStream = cs.putVideo("Mask", 320, 240)

# Allocating new images is very expensive, always try to preallocate
img = np.zeros(shape=(240, 320, 3), dtype=np.uint8)
maskFinal = np.zeros(shape=(240, 320, 3), dtype=np.uint8)
processin = processor.Processor()

while True:
	if serial_comms.shouldTakePhoto:
		cameraSink = {}
		if serial_comms.shouldTakePhotoRight:
			cameraSink = cameraRightSink
		else:
			cameraSink = cameraLeftSink

		# Tell the CvSink to grab a frame from the camera and put it
		# in the source image.  If there is an error notify the output.
		timestamp, img = cameraSink.grabFrame(img)

		if timestamp == 0:
			# Send the output the error.
			outputStream.notifyError(cameraSink.getError());
			# skip the rest of the current iteration
			continue
		img = cv2.flip(img, 0)

		rodData, maskFinal = processin.process(img)
		rodData = [["r", "b", "g", "r"], ["b", "g", "b", "b"]]

		serial_comms.shouldTakePhoto = False
		serial_comms.sendRods(rodData)

	outputStream.putFrame(img)
	maskStream.putFrame(maskFinal)
	time.sleep(0.06)
