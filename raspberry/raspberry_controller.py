from __future__ import print_function
from inputs import get_gamepad
import serial
import time

dataMotor=[0,0,0,0,0]
axe_X=0
axe_Y=0
axe_RX=0
axe_RY=0
triangle=0
carre=0
rond=0
croix=0

step=0
speed=1000
speed_temp=1000
dir=0
dir_temp=0

arduino_serial = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)
arduino_serial.flush()

while 1:
    events = get_gamepad()
    for event in events:
        if event.code == "ABS_Y" and event.state < -10000 :
            axe_Y=-1
        elif event.code == "ABS_Y" and event.state > 10000 :
            axe_Y=1
        elif event.code == "ABS_Y" and event.state < 10000 and event.state > -10000:
            axe_Y=0

        if event.code == "ABS_X" and event.state < -10000 :
            axe_X=-1
        elif event.code == "ABS_X" and event.state > 10000 :
            axe_X=1
        elif event.code == "ABS_X" and event.state < 10000 and event.state > -10000:
            axe_X=0

        if event.code == "ABS_RY" and event.state < -10000 :
            axe_RY=-1
        elif event.code == "ABS_RY" and event.state > 10000 :
            axe_RY=1
        elif event.code == "ABS_RY" and event.state < 10000 and event.state > -10000:
            axe_RY=0

        if event.code == "ABS_RX" and event.state < -10000 :
            axe_RX=-1
        elif event.code == "ABS_RX" and event.state > 10000 :
            axe_RX=1
        elif event.code == "ABS_RX" and event.state < 10000 and event.state > -10000:
            axe_RX=0





        if event.code == "BTN_WEST":
            triangle= event.state
        if event.code == "BTN_EAST":
            rond= event.state
        if event.code == "BTN_SOUTH":
            croix= event.state
        if event.code == "BTN_NORTH":
            carre= event.state



        if event.code =="BTN_TR" and event.state == 1 :
            speed = speed + 100
        if event.code =="BTN_TL" and event.state == 1 :
            speed = speed - 100


        if axe_X == 0 and axe_Y== 0 :
            dir=0

        if axe_Y == -1 and axe_RY== 1 :
            dir=20

        if axe_Y == 1 and axe_RY== -1 :
            dir=19


        if axe_Y== -1 and triangle == 1 :
            dir=12

        if axe_Y== -1 and rond == 1 :
            dir=13

        if axe_Y== -1 and carre == 1 :
            dir=11

        if axe_Y== 1 and croix == 1 :
            dir=17

        if axe_Y== 1 and rond == 1 :
            dir=18

        if axe_Y== 1 and carre == 1 :
            dir=16



        if axe_X== -1 and triangle == 1 :
            dir=11

        if axe_X== -1 and croix == 1 :
            dir=16

        if axe_X== -1 and carre == 1 :
            dir=14

        if axe_X== 1 and croix == 1 :
            dir=18

        if axe_X== 1 and rond == 1 :
            dir=15

        if axe_X== 1 and triangle == 1 :
            dir=13


        if dir_temp != dir or speed_temp != speed:
            dir_temp=dir
            speed_temp=speed
            dataMotor[0] = step >> 8;
            dataMotor[1] = step - ((step >> 8) * 256);
            dataMotor[2] = dir;
            dataMotor[3] = speed >> 8;
            dataMotor[4] = speed - ((speed >> 8) * 256);
            for x in range (0,5):

            	arduino_serial.write((dataMotor[x]).to_bytes(1, byteorder='big'))
            arduino_serial.write(b'\n')
            print(dir)
