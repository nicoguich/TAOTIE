#!/bin/bash 

sleep 5 &
python3 /home/pi/Desktop/raspberry_camera.py &
python3 /home/pi/Desktop/raspberry_main.py &
sleep 20 &
python3 /home/pi/Desktop/raspberry_controller.py &
