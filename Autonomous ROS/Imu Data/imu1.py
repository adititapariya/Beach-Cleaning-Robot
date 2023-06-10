#!/usr/bin/env python3
import rospy
from std_msgs.msg import Float64
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Quaternion

rospy.init_node('imu1')

def callback(msg): 
    print (msg.orientation)
    print(" ")
     
    
sub = rospy.Subscriber('/imu', Imu , callback)
rospy.spin()
	
