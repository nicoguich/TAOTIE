#!/bin/bash 

sudo /home/pi/Desktop/Chataigne-linux-armhf-1.9.6.AppImage &
sleep 5
print "toto"
xdotool search "Chataigne" windowmove 514 635 windowsize 1910 420 &

#python3 /home/pi/Desktop/raspberry_camera.py &
#python3 /home/pi/Desktop/raspberry_main.py &
#python3 /home/pi/Desktop/raspberry_controller.py &> /home/pi/Desktop/error_controller.txt &

