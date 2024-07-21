#!/usr/bin/env python3
import math
import rospy
from std_msgs.msg import Float64

rospy.init_node('imu1')

pub= rospy.Publisher('imu', Float64 , queue_size = 10)  

def callback(msg):
    global heading 
    heading = Float64()
    heading = msg.data 
    print (heading)
    pub.publish(heading)
         
    
sub = rospy.Subscriber('/arimu', Float64 , callback)
rate = rospy.Rate(10)  # Adjust the rate as needed   
rospy.spin()
