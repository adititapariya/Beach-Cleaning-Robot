#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist
from std_msgs.msg import Float64
rospy.init_node('sub')
v = 0.075
v1=0.075
pub1 = rospy.Publisher('/farm_bot/leftWheelfront_effort_controller/command', Float64, queue_size = 10)
pub2 = rospy.Publisher('/farm_bot/leftWheelrear_effort_controller/command', Float64, queue_size = 10)
pub3 = rospy.Publisher('/farm_bot/rightWheelfront_effort_controller/command',Float64, queue_size = 10)
pub4 = rospy.Publisher('/farm_bot/rightWheelrear_effort_controller/command', Float64, queue_size = 10)

def callback(msg):
    print (msg.linear.x)
    print (msg.angular.z)
    print(" ")
    global move
    move = Float64()
    move.data = (msg.linear.x)*v
    global turn
    turn = Float64()
    turn.data= (msg.angular.z)*v1
   
    vel1=move.data+turn.data
    vel2=move.data-turn.data
    
    pub1.publish(vel1) 
    pub2.publish(vel1)
    pub3.publish(vel2)
    pub4.publish(vel2)
    
    
sub = rospy.Subscriber('cmd_vel', Twist, callback)
rospy.spin()
