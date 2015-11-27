#!/usr/bin/python
import argparse
import time
import serial
import sys

#serial port write with delay function
def serDelWrite(ser,line,delay):
      for c in line:
            ser.write(c)
            time.sleep(delay)

#progress bar update and draw function
def drawProgressBar(percent, barLen):
    sys.stdout.write("\r")
    progress = ""
    for i in range(barLen):
        if i < int(barLen * percent):
            progress += "="
        else:
            progress += " "
    sys.stdout.write("[ %s ] %.2f%%" % (progress, percent * 100))
    sys.stdout.flush()

#start of main program
#argument parsing
parser = argparse.ArgumentParser(description='Hex Programmer Utility')


args         = vars(parser.parse_args())

#setup serial port
ser = serial.Serial(
	port='/dev/ttyUSB0',
	baudrate=115200,
	parity=serial.PARITY_NONE,
	stopbits=serial.STOPBITS_ONE,
	bytesize=serial.EIGHTBITS,
	timeout=.1
)

while(True):
	#ser.write('LOAD_PROGRAM\n');
	#ret = ser.readline()
	#print ret

        ser.write('EXECUTE_PROGRAM\n');
        ret = ser.readline()
        print ret

        ser.write('REG_READ\n');
        ret = ser.readline()
        print ret

        ser.write('REG_WRITE\n');
        ret = ser.readline()
        print ret
	time.sleep(1)



