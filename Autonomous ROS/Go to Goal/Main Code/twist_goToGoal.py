#!/usr/bin/env python
import rospy
import math
from std_msgs.msg import Float64
from sensor_msgs.msg import Imu
from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import Quaternion
from geometry_msgs.msg import Twist
from math import sin, cos, sqrt, atan2, radians

rospy.init_node('twist1')

l=float()
a=float()
vel=Twist()

          
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

    global theta
    theta = yaw_z
    
    print('YAW=',yaw_z)

def callback1(msg):
    global l,a
    global Lat
    Lat = Float64()
    Lat = msg.latitude
    print ("Latitude= ", Lat)
   
    global Long
    Long = Float64()
    Long = msg.longitude
    print ("Longitude= ", Long)
    #print(" ")

    R=6371.0        #radius of earth

    lat1 = radians(Lat)
    lon1 = radians(Long)
    lat2 = radians(49.900000364122505)  #specified destination
    lon2 = radians(8.900042071570175)

    dlon = lon2 - lon1
    dlat = lat2 - lat1
    
    a = sin(dlat / 2)**2 + cos(lat1) * cos(lat2) * sin(dlon / 2)**2
    c = 2 * atan2(sqrt(a), sqrt(1 - a))
    
    global dist  
    dist = Float64()
    dist = R*c*1000

    print("Result:", dist)          #to travel
   
    global A
    A = Float64()
    A = atan2 (dlat, dlon)
    print('angle_to_goal: ',A)
    global angle 
    angle = Float64()
    angle = A - theta
    print("angle =",angle)
    print(" ")
    
    if (angle > 0.1 and angle < 3.13) or (angle > -3.13 and angle < -6.27):
        l=0
        a=-1
        
    elif (angle > 3.13 and angle < 6.27) or (angle < -0.1 and angle > -3.13):
        l=0
        a=1
        
    else :
        
        if dist > 1.5 :
            l=0.5
            a=0
    
        else :
            l=0
            a=0
       
        
    vel.linear.x=l
    vel.angular.z=a
    pub.publish(vel)

pub=rospy.Publisher('cmd_vel',Twist,queue_size=10)
sub = rospy.Subscriber('/imu', Imu , callback)
sub = rospy.Subscriber('/fix', NavSatFix, callback1)
rospy.spin()
