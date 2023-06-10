#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Range
from std_msgs.msg import Float32

def callback(msg):
	print(msg.range)	
rospy.init_node('obstacle1')
sub = rospy.Subscriber('sensor/ir_front', Range , callback)
rospy.spin()

