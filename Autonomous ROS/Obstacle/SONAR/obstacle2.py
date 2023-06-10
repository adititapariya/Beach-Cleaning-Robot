#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Range
from std_msgs.msg import Float32

def callback1(msg):
	global L
	L = Float32()
	L.data = msg.range
	#print('L=' ,msg.range)
	print(L)
	
def callback2(msg):
	global LS
	LS = Float32()
	LS.data = msg.range
	print(LS)
	#print('LS=' ,msg.range)

def callback3(msg):
	global F
	F = Float32()
	F.data = msg.range
	print(F)
	#print('F=' ,msg.range)
	
def callback4(msg):
        global RS
        RS = Float32()
        RS.data = msg.range
        print(RS)
	#print('RS=' ,msg.range)
	
def callback5(msg):
        global R
        R = Float32()
        R.data = msg.range
        print(R)
        print()
	
rospy.init_node('obstacle2')
sub1 = rospy.Subscriber('sensor/ir_left', Range , callback1)
sub2 = rospy.Subscriber('sensor/ir_leftslant', Range , callback2)
sub3 = rospy.Subscriber('sensor/ir_front', Range , callback3)
sub4 = rospy.Subscriber('sensor/ir_rightslant', Range , callback4)
sub5 = rospy.Subscriber('sensor/ir_right', Range , callback5)

rospy.spin()
