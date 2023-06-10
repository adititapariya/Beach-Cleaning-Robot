#!/usr/bin/env python3
import math
import rospy
from std_msgs.msg import Float64MultiArray
from std_msgs.msg import Float64
from std_msgs.msg import MultiArrayLayout
from sensor_msgs.msg import NavSatFix

gps = Float64MultiArray()
rospy.init_node('gps1')
pub= rospy.Publisher('gps', Float64MultiArray , queue_size = 10)  

def callback(msg):
    global gps
    gps.data= [0,0]
    gps.data[0]=msg.latitude
    gps.data[1]=msg.longitude
    print(gps.data)
    pub.publish(gps)
           
sub = rospy.Subscriber('/fix', NavSatFix , callback)
rate=rospy.Rate(2)
rospy.spin()
	

	


