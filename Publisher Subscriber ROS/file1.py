#!/usr/bin/env python

import rospy

from std_msgs.msg import Float32


rospy.init_node('file1')

pub=rospy.Publisher('counter',Float32,queue_size=10)

rate = rospy.Rate(2)

count=0
while not rospy.is_shutdown():
	pub.publish(count)
	count +=1
	rate.sleep()
	
