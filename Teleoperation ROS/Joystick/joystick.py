#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Joy

rospy.init_node('joystick')

def callback(msg):
    
    print("Axes: ",msg.axes)
    print("Buttons: ",msg.buttons)
    print(" ")

sub = rospy.Subscriber('joy', Joy , callback)
rospy.spin()
