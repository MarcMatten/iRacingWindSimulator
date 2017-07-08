import irsdk
import serial
import serial.tools.list_ports
import struct
from pygame import *

# find serial port for Arduino Leonardo
PortList = serial.tools.list_ports.comports()
portFound = 0
for i in range(1,len(PortList)):
    if PortList[i].description[0:16] == 'Arduino Leonardo':
        COMPort = PortList[i].device
        portFound = 1

if portFound == 1:
    print('Arduino found! Connecting to', COMPort)

    ser = serial.Serial('COM8', 9600, timeout=1)
    time.wait(2000)
    ser.write(struct.pack('>B', 0))

    print('Connection established!')

    ir = irsdk.IRSDK()
    while ir.startup():
        ser.write(struct.pack('>B', 0))

        if(ir['IsOnTrack']):
            speed = ir['Speed']
            fanSpeed = int(3.06*speed)
            ser.write(struct.pack('>B', fanSpeed))
            print(fanSpeed)
elif portFound == 0:
    print('Arduino not found!... Terminating!')
    quit()