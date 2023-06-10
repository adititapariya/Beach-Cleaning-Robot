#!/usr/bin/env python3
import rospy
#import importlib
#moduleName = input('message_pub')
#importlib.import_module(message_pub)
from message_pub.msg import Complex
from random import random
rospy.init_node('pub')
pub = rospy.Publisher('complex', Complex)
rate = rospy.Rate(2)
while not rospy.is_shutdown():
    msg = Complex()
    msg.real = 5.0
    msg.imaginary = 4.9
    pub.publish(msg)
    rate.sleep()
