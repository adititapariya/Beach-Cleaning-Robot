#!/usr/bin/env python3

import rospy
from std_msgs.msg import Float64
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Range

rospy.init_node('obstacle')
vf = 0.04
vb = -0.04
s =0

pub1 = rospy.Publisher('/farm_bot/leftWheelfront_effort_controller/command', Float64, queue_size = 10)
pub2 = rospy.Publisher('/farm_bot/leftWheelrear_effort_controller/command', Float64, queue_size = 10)
pub3 = rospy.Publisher('/farm_bot/rightWheelfront_effort_controller/command', Float64, queue_size = 10)
pub4 = rospy.Publisher('/farm_bot/rightWheelrear_effort_controller/command', Float64, queue_size = 10)

def clbkL(msg):
    global L 
    L = Float64
    L = msg.range
    print ('L= ',L)
    print (" ")

def clbkLS(msg):
    global LS
    LS = Float64
    LS = msg.range
    print ('LS= ',LS)
    print (" ")

def clbkF(msg):
    global F
    F = Float64
    F = msg.range
    print ('F= ',F)
    print (" ")
    
def clbkRS(msg):
    global RS
    RS = Float64
    RS = msg.range
    print ('RS= ',RS)
    print (" ")

def clbkR(msg):
    global R
    R = Float64
    R = msg.range
    print ('R= ',R)
    print (" ")
  
L = rospy.Subscriber('left', Range, clbkL)
LS = rospy.Subscriber('ls', Range, clbkLS)
F = rospy.Subscriber('front', Range, clbkF)
RS = rospy.Subscriber('rs', Range, clbkRS)
R = rospy.Subscriber('right', Range, clbkR)

rate = rospy.Rate(20)
while not rospy.is_shutdown():
    if F==1:
        if RS==0.75 and LS==0.75:
            pub1.publish(vf*0.8)
            pub2.publish(vf*0.8)
            pub3.publish(vf*0.8)
            pub4.publish(vf*0.8)

        elif RS!=0.75 and LS!=0.75 and R==0.5 and L==0.5:
            pub1.publish(vf*0.8)
            pub2.publish(vf*0.8)
            pub3.publish(vf*0.8)
            pub4.publish(vf*0.8)

        elif RS!=0.75 and LS!=0.75 and R!=0.5 and L!=0.5:
            pub1.publish(vf*0.8)
            pub2.publish(vf*0.8)
            pub3.publish(vf*0.8)
            pub4.publish(vf*0.8)

        elif RS!=0.75 and LS==0.75:
            pub1.publish(vb)
            pub2.publish(vb)
            pub3.publish(2*vf)
            pub4.publish(2*vf)

        elif RS==0.75 and LS!=0.75:
            pub1.publish(2*vf)
            pub2.publish(2*vf)
            pub3.publish(vb)
            pub4.publish(vb)

        else:
            pub1.publish(vf*0.9)
            pub2.publish(vf*0.9)
            pub3.publish(vf*0.9)
            pub4.publish(vf*0.9)
    
    elif F!=1:
        if L==0.5 and LS==0.75 and (R!=0.5 or RS!=0.75):
            pub1.publish(2.5*vb)
            pub2.publish(2.5*vb)
            pub3.publish(2.5*vf)
            pub4.publish(2.5*vf)

        elif R==0.5 and RS==0.75 and (L!=0.5 or LS!=0.75):
            pub1.publish(2.5*vf)
            pub2.publish(2.5*vf)
            pub3.publish(2.5*vb)
            pub4.publish(2.5*vb)

        elif (L==0.5 and LS==0.75 and RS==0.75 and R==0.5) or (LS!=0.75 and R!=0.5) or (RS!=0.75 and LS!=0.75) or (L!=0.5 and R!=0.5) or (L!=0.5 and RS!=0.75):
            pub1.publish(vf)
            pub2.publish(vf)
            pub3.publish(2*vb)
            pub4.publish(2*vb)

        else:
            pub1.publish(vf*0.9)
            pub2.publish(vf*0.9)
            pub3.publish(vf*0.9)
            pub4.publish(vf*0.9)

    rate.sleep()

rospy.spin()
