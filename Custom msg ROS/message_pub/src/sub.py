#!/usr/bin/env python3
import rospy
import importlib
moduleName = input('message_pub')
importlib.import_module(message_pub)
from message_pub.msg import Complex
def callback(msg):
    print ('Real:', msg.real)
    print ('Imaginary:', msg.imaginary)
    print ()
rospy.init_node('sub')
sub = rospy.Subscriber('complex', Complex, callback)
rospy.spin()
