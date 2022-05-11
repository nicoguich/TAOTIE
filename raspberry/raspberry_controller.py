

import inputs
from osc4py3.as_eventloop import *
from osc4py3 import oscbuildparse
import time



osc_startup()
osc_udp_client("127.0.0.1", 5005, "raspberry")
osc_udp_client("127.0.0.1", 5006, "camera")


with open("/home/pi/Desktop/reglage_camera.txt") as f:
    reglage_lines = f.readlines()
brightness=int (reglage_lines[0])
contrast=int (reglage_lines[1])
thresh=int(reglage_lines[2])
reverse=int(reglage_lines[3])


data=[0,0]
axe_X=0
axe_Y=0
axe_RX=0
axe_RY=0
triangle=0
carre=0
rond=0
croix=0
dir=0
speed=1000
select=0
start=0
home=0
led_fat=1
led_ir=1
control_position=1
control_value=0
sel_control=0
image=0
stop=0
sel_stop=0


msg = oscbuildparse.OSCMessage("/controller", None, data)
osc_send(msg, "raspberry")
osc_process()





while True :
    events = inputs.get_gamepad()

    for event in events:


        if event.code=="ABS_HAT0Y" and sel_control==0 :
            if event.state==1:
                led_ir =1
            else:
                led_ir=0
            if event.state==-1:
                led_fat=1
            else:
                led_fat=0



        if event.code == "BTN_MODE" and sel_control==0:
            home=event.state

        if event.code=="BTN_START" and sel_control==0 :

                start =event.state



        if event.code=="BTN_SELECT" and event.state==1 and sel_control==0:

            select =abs(select-1)

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
        if event.code == "BTN_SOUTH" and sel_stop==0:
            croix= event.state
        if event.code == "BTN_NORTH":
            carre= event.state



        if event.code =="BTN_TR" and event.state == 1 :
            speed = speed + 100
        if event.code =="BTN_TL" and event.state == 1 :
            speed = speed - 100


        if event.code == "ABS_RZ":

            if event.state >100:
                sel_control=1
            else:
                sel_control=0

        if event.code == "ABS_Z":

            if event.state >100:
                sel_stop=1
            else:
                sel_stop=0


        if event.code == "ABS_HAT0X" and sel_control==1 :

            control_position += event.state
            if control_position>3:
                control_position=1
            if control_position<1:
                control_position=3

        if event.code=="ABS_HAT0Y" and control_position==1 :
            brightness += event.state*-1
            if brightness>=100:
                brightness=100
            if brightness<=0:
                brightness=0

        if event.code=="ABS_HAT0Y" and control_position==2 :
            contrast += event.state*-1
            if contrast<=-100:
                contrast=-100
            if contrast>=100:
                contrast=100

        if event.code=="ABS_HAT0Y" and control_position==3 :
            thresh += event.state*-1
            if thresh>=255:
                thresh=255
            if thresh<=0:
                thresh=0

        if event.code=="BTN_SELECT" and sel_control==1 :
                if event.state==1:
                    reverse = abs(reverse-1)

        if event.code=="BTN_MODE" and sel_control==1 :
                if event.state==1:
                    image = abs(image-1)


        if event.code=="BTN_SOUTH" and sel_stop==1 :

            stop = event.state


        if event.code=="BTN_START" and sel_control==1 :
                if event.state==1:
                    print("enregistrement reglage camera...")
                    reglage_camera = open("/home/pi/Desktop/reglage_camera.txt","w")
                    print("...")
                    reglage_camera.write(str(int(brightness))+"\n")
                    print("...")
                    reglage_camera.write(str(int(contrast))+"\n")
                    print("...")
                    reglage_camera.write(str(int(thresh))+"\n")
                    print("...")
                    reglage_camera.write(str(int(reverse))+"\n")
                    reglage_camera.close()
                    print("reglage enregistré")


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


        if sel_control==1:
            data_cam=[control_position,brightness,contrast,thresh,reverse,image]
            msg_control = oscbuildparse.OSCMessage("/image", None, data_cam)
            osc_send(msg_control, "camera")
            osc_process()
            #print(data_cam)

        else:
            data=[dir,speed,select,home,start,led_ir,led_fat,stop]
            msg = oscbuildparse.OSCMessage("/controller", None, data)
            osc_send(msg, "raspberry")
            osc_process()
            #print(data)


osc_terminate()
