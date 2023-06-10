#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Joy
from std_msgs.msg import Float64
rospy.init_node('ps3contr')
v = 0.035


def callback(msg):
    print (msg.axes[3])
    print (msg.axes[0])
    print(" ")
    global move
    move = Float64()
    move.data = (msg.axes[3])*v
    global turn
    turn = Float64()
    turn.data = (msg.axes[0])*v
    vel1=move.data+turn.data
    vel2=move.data-turn.data
    pub1 = rospy.Publisher('/farm_bot/leftWheelfront_effort_controller/command', Float64, queue_size = 10)
    pub2 = rospy.Publisher('/farm_bot/leftWheelrear_effort_controller/command', Float64, queue_size = 10)
    pub3 = rospy.Publisher('/farm_bot/rightWheelfront_effort_controller/command', Float64, queue_size = 10)
    pub4 = rospy.Publisher('/farm_bot/rightWheelrear_effort_controller/command', Float64, queue_size = 10)

    pub1.publish(vel2) 
    pub2.publish(vel2)
    pub3.publish(vel1)
    pub4.publish(vel1)

sub = rospy.Subscriber('joy', Joy, callback)
rospy.spin()
