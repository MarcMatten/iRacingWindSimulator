import serial
import struct
import time

ser = serial.Serial('COM3', 9600, timeout=1)

for i in range(0,20):
    t = time.perf_counter()
    ser.write(struct.pack('>bbbbbbb', 0,0,0,0,0,0,0))
    print((time.perf_counter() - t) * 1000)

print('===================')

time.sleep(0.3)

t = time.perf_counter()
ser.write(struct.pack('>BBBBBBB', 0,1,0,0,0,0,0))
print((time.perf_counter() - t) * 1000)

time.sleep(0.3)

print('===================')

for i in range(0,9):
    t = time.perf_counter()
    ser.write(struct.pack('>bbbbbbb', 0,0,i,0,0,0,0))
    print((time.perf_counter() - t) * 1000)
    time.sleep(0.3)
    
print('===================')


t = time.perf_counter()
ser.write(struct.pack('>BBBBBBB', 0,0,0,0,0,0,0))
print((time.perf_counter() - t) * 1000)


time.sleep(0.3)

for i in range(0,5):
    t = time.perf_counter()
    ser.write(struct.pack('>BBBBBBB', 0,0,0,i,0,0,0))
    print((time.perf_counter() - t) * 1000)
    time.sleep(0.3)

t = time.perf_counter()
ser.write(struct.pack('>BBBBBBB', 0,0,0,0,0,0,0))
print((time.perf_counter() - t) * 1000)

time.sleep(1)

for i in range(0,5):
    t = time.perf_counter()
    ser.write(struct.pack('>BBBBBBB', 0,0,0,0,i,0,0))
    print((time.perf_counter() - t) * 1000)
    time.sleep(0.5)

t = time.perf_counter()
ser.write(struct.pack('>BBBBBBB', 0,0,0,0,0,0,0))
print((time.perf_counter() - t) * 1000)

time.sleep(0.3)

for i in range(0,5):
    t = time.perf_counter()
    ser.write(struct.pack('>BBBBBBB', 0,0,0,0,0,i,0))
    print((time.perf_counter() - t) * 1000)
    time.sleep(0.3)

t = time.perf_counter()
ser.write(struct.pack('>BBBBBBB', 0,0,0,0,0,0,0))
print((time.perf_counter() - t) * 1000)

time.sleep(0.3)

for i in range(0,5):
    t = time.perf_counter()
    ser.write(struct.pack('>BBBBBBB', 0,0,0,0,0,0,i))
    print((time.perf_counter() - t) * 1000)
    time.sleep(0.3)

t = time.perf_counter()
ser.write(struct.pack('>BBBBBBB', 0,0,0,0,0,0,0))
print((time.perf_counter() - t) * 1000)

ser.close()


