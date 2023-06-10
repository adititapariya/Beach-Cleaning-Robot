#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Float32



def callback(msg):
    global i
    i=0
    for i in range(5):
        
        print(msg.ranges[i])	
        i=i+1
    print()   
rospy.init_node('obstacle1')
sub = rospy.Subscriber('rrbot/laser/scan', LaserScan , callback)
rospy.spin()
