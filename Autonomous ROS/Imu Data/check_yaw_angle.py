#!/usr/bin/env python3
import math
import rospy
from math import sin, cos, sqrt, atan2, radians
from std_msgs.msg import Float64
from sensor_msgs.msg import Imu
from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import Quaternion

rospy.init_node('imu1')

def callback(msg):
    global x
    x = Float64()
    x = msg.orientation.x
    #print('x=', x)
   
    global y
    y = Float64()
    y = msg.orientation.y
    #print('y=', y)
    
    global z
    z = Float64()
    z = msg.orientation.z
    #print('z=', z)
    
    global w
    w = Float64()
    w = msg.orientation.w
    #print('w=', w)
    
    t3 = +2.0 * (w * z + x * y)
    t4 = +1.0 - 2.0 * (y * y + z * z)
    yaw_z = math.atan2(t3, t4)
    print('Yaw=',yaw_z)
    
    global theta
    theta = yaw_z

 
def callback1(msg):    
    global Lat
    Lat = Float64()
    Lat = msg.latitude
    print ("Latitude= ", Lat)
   
    global Long
    Long = Float64()
    Long = msg.longitude
    print ("Longitude= ", Long)
    print(" ")
    
    R=6373.0        #radius of earth

    lat1 = radians(Lat)
    lon1 = radians(Long)
    lat2 = radians(5.904e-06)  #specified destination
    lon2 = radians(3.9e-08)

    dlon = lon2 - lon1
    dlat = lat2 - lat1
    
    global A
    A = Float64()
    A = atan2 (dlat, dlon)
    print('angle_to_goal: ',A)  
    global angle 
    angle = Float64()
    angle = A - theta
    print("angle =",angle)
    print(" ")   
       
sub = rospy.Subscriber('/imu', Imu , callback)
sub = rospy.Subscriber('/fix', NavSatFix, callback1)
rospy.spin()
	



	
		
