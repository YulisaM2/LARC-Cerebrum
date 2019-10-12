import threading
import serial
from datetime import datetime

port = "/dev/ttyACM0"
baud = 9600

serial_port = serial.Serial(port, baud)

shouldTakePhotoRightCommand = "pr\n"
shouldTakePhotoLeftCommand = "pl\n"
shouldTakePhoto = False
shouldTakePhotoRight = False

def handle_data(data):
	global shouldTakePhoto
	global shouldTakePhotoRight

	now = datetime.now()
	dt_string = now.strftime("%d/%m/%Y %H:%M:%S")

	print("Read from arduino at time {}: {}".format(dt_string, data))
	if data == shouldTakePhotoRightCommand:
		shouldTakePhoto = True
		shouldTakePhotoRight = True

	if data == shouldTakePhotoLeftCommand:
		shouldTakePhoto = True
		shouldTakePhotoRight = False

def read_from_port(ser):
	while True:
		reading = ser.readline().decode()
		handle_data(reading)

def sendRods(rodData):
	serial_port.write(bytearray("$", "utf-8"))
	for stack in rodData:
		for rod in stack:
			serial_port.write(bytearray(rod, "utf-8"))
	serial_port.write(bytearray("\n", "utf-8"))

thread = threading.Thread(target=read_from_port, args=(serial_port, ))
thread.start()

