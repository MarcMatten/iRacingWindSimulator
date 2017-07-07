import irsdk
import serial
import struct
from pygame import *

ir = irsdk.IRSDK()

ser = serial.Serial('COM4', 9600, timeout=1)
time.wait(2000)
ser.write(struct.pack('>B', 0))

while ir.startup():
    ser.write(struct.pack('>B', 0))

    if(ir['IsOnTrack']):
        speed = ir['Speed']
        fanSpeed = int(3.06*speed)
        ser.write(struct.pack('>B', fanSpeed))
        print(fanSpeed)