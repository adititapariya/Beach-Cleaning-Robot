#!/usr/bin/env python3
import math
import rospy
from std_msgs.msg import Float64
from sensor_msgs.msg import NavSatFix

rospy.init_node('gps1')

pub1= rospy.Publisher('lat', Float64 , queue_size = 10)  
pub2= rospy.Publisher('lon', Float64 , queue_size = 10)  

def callback(msg):
    global lat,lon
    lat = Float64()
    lon = Float64()
    lat = msg.latitude
    lon = msg.longitude
    print (lat)
    print (lon)
    print(" ")
    pub1.publish(lat)
    pub2.publish(lon)
         
    
sub = rospy.Subscriber('/fix', NavSatFix , callback)

rospy.spin()
	

	
