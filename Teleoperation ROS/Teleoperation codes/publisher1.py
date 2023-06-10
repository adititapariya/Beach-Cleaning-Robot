#!/usr/bin/env python3

import rospy
from std_msgs.msg import Float64
rospy.init_node('farm_bot')
pub1 = rospy.Publisher('/farm_bot/leftWheelfront_effort_controller/command', Float64, queue_size = 10)
pub2 = rospy.Publisher('/farm_bot/leftWheelrear_effort_controller/command', Float64, queue_size = 10)
pub3 = rospy.Publisher('/farm_bot/rightWheelfront_effort_controller/command', Float64, queue_size = 10)
pub4 = rospy.Publisher('/farm_bot/rightWheelrear_effort_controller/command', Float64, queue_size = 10)
rate = rospy.Rate(2)

while True:
    vel = 0.05
    velo = -0.05
    stop = 0
    data = str(input("press any key: "))


    if data == 'w':
            pub1.publish(vel)
            pub2.publish(vel)
            pub3.publish(vel)
            pub4.publish(vel)
            rate.sleep()

    elif data == 'a':
            pub1.publish(velo)
            pub2.publish(velo)
            pub3.publish(vel)
            pub4.publish(vel)
            rate.sleep()

    elif data == 'd':
            pub1.publish(vel)
            pub2.publish(vel)
            pub3.publish(velo)
            pub4.publish(velo)
            rate.sleep()
        
    elif data == 's':
            pub1.publish(velo)
            pub2.publish(velo)
            pub3.publish(velo)
            pub4.publish(velo)
            rate.sleep()

    elif data == 'c':
            pub1.publish(stop)
            pub2.publish(stop)
            pub3.publish(stop)
            pub4.publish(stop)
            rate.sleep(
