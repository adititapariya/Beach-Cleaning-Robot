#!/usr/bin/env python3
import math
import rospy
from std_msgs.msg import Float64
from sensor_msgs.msg import NavSatFix

rospy.init_node('gps1')

def callback(msg):
    print ("Latitude= ",msg.latitude)
    print ("Longitude= ",msg.longitude)
    print(" ")
         
    
sub = rospy.Subscriber('/fix', NavSatFix , callback)
rospy.spin()
	



	
		
