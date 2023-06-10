#!/usr/bin/env python3
import rospy
from std_msgs.msg import Float32
rospy.init_node('Harshil')
pub = rospy.Publisher('Mistry', Float32, queue_size = 10)
rate = rospy.Rate(10)
count = 0
a = 1
while not rospy.is_shutdown():
    pub.publish(count)
    count += a;
    if count > 255:
       a = -1;
    elif count < 0:
       a = 1;
    rate.sleep()
