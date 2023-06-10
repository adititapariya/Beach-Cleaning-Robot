#!/usr/bin/env python


import rospy
from std_msgs.msg import Float32

def callback(msg):
	print(msg.data)
	
rospy.init_node('file2')

sub = rospy.Subscriber('counter', Float32 , callback)

rospy.spin()

