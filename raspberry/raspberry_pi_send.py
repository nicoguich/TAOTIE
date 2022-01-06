
import serial
import time
dataMotor=[0,0,0,0,0]

compteur=0
step=2000
speed=1000
dir=0
arduino_serial = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)
arduino_serial.flush()
dataMotor[0] = step >> 8;
dataMotor[1] = step - ((step >> 8) * 256);
dataMotor[2] = dir;
dataMotor[3] = speed >> 8;
dataMotor[4] = speed - ((speed >> 8) * 256);


for x in range (0,5):
	print(dataMotor[x])
	arduino_serial.write((dataMotor[x]).to_bytes(1, byteorder='big'))
arduino_serial.write(b'\n')
#line = arduino_serial.readline().decode('utf-8').rstrip()
#print(line)
print("toto")

#time.sleep(1)
