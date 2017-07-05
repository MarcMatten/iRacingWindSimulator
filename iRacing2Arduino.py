import irsdk
import serial

ir = irsdk.IRSDK()

ser = serial.Serial('COM4', 9600, timeout=0)
ser.write(b'0')

while ir.startup():
    gear = ir['Gear']
    speed = ir['Speed']

    if gear == 0:
        ser.write(b'1')
    elif speed*3.6 >= 16:
        ser.write(b'1')
    else:
        ser.write(b'0')