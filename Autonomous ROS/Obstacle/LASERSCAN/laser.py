#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Float32

def callback(msg):
	print(msg.ranges)	
rospy.init_node('obstacle1')
sub = rospy.Subscriber('rrbot/laser/scan', LaserScan , callback)
rospy.spin()

