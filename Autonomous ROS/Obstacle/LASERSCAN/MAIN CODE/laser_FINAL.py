#!/usr/bin/env python3

import rospy
from std_msgs.msg import Float64
from sensor_msgs.msg import LaserScan

L=0.03
A=0.01
rospy.init_node('obstacle')

pub1 = rospy.Publisher('/farm_bot/leftWheelfront_effort_controller/command', Float64, queue_size = 10)
pub2 = rospy.Publisher('/farm_bot/leftWheelrear_effort_controller/command', Float64, queue_size = 10)
pub3 = rospy.Publisher('/farm_bot/rightWheelfront_effort_controller/command', Float64, queue_size = 10)
pub4 = rospy.Publisher('/farm_bot/rightWheelrear_effort_controller/command', Float64, queue_size = 10)

rate=rospy.Rate(10)
num=[0,0,0,0,0]

def callback(msg):
    global i
    
    for i in range(5):
        num[i]=msg.ranges[i]
        #print(num[i])
    #print(num)
    
    if num[0]>=3:
        num[0]=4
     
    if num[1]>=3:
        num[1]=6
  
    if num[2]>=3:
        num[2]=1
        
    if num[3]>=3:
        num[3]=6
        
    if num[4]>=3:
        #num.insert(4,5)
        num[4]=4
    print(num)
    print()
     
    d=-num[0]-num[1]+num[3]+num[4]
    
    if num[2] == 1 :
        vel1 = 0.03
        vel2 = 0.03
    
    if num[2] < 1.0 and d <= 0.05 :
        vel1 = -0.0095
        vel2 = -0.175
        
    else :
        vel1=L+A*(1.2*d)
        vel2=L-A*(1.2*d)
    
    pub1.publish(vel1)
    pub2.publish(vel1)
    pub3.publish(vel2)
    pub4.publish(vel2)
    print(vel1)
    print(vel2)
    print(d)
    
    rate.sleep()
    
    
sub = rospy.Subscriber('rrbot/laser/scan', LaserScan , callback)


rospy.spin()
