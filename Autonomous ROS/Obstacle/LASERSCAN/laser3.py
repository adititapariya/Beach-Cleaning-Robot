#!/usr/bin/env python3

import rospy
from std_msgs.msg import Float64
from sensor_msgs.msg import LaserScan

rospy.init_node('obs')
v= 0.05
s= 0
pub1 = rospy.Publisher('/farm_bot/leftWheelfront_effort_controller/command', Float64, queue_size = 10)
pub2 = rospy.Publisher('/farm_bot/leftWheelrear_effort_controller/command', Float64, queue_size = 10)
pub3 = rospy.Publisher('/farm_bot/rightWheelfront_effort_controller/command', Float64, queue_size = 10)
pub4 = rospy.Publisher('/farm_bot/rightWheelrear_effort_controller/command', Float64, queue_size = 10)


def callback(msg):
    for i in range(5):
    
        if msg.ranges[i] >= 1 :
            pub1.publish(v)
            pub2.publish(v)
            pub3.publish(v)
            pub4.publish(v)
      

sub= rospy.Subscriber('rrbot/laser/scan', LaserScan, callback)   
rospy.spin()
