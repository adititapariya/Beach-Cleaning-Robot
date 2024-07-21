#!/usr/bin/env python3
import math
import rospy
import time
from std_msgs.msg import Float64
from std_msgs.msg import Float64MultiArray
from sensor_msgs.msg import NavSatFix
from math import sin, cos, sqrt, atan2, radians

rospy.init_node('gps1')

pub= rospy.Publisher('dist', Float64MultiArray , queue_size = 10)  
terminate = False
sub = None
gps_msg = None
send = Float64MultiArray()
send.data = [0,0,0]
def callbackGPS(msg):
    global gps_msg
    gps_msg = msg
    print("Got")
    # lat = Float64()
    # lon = Float64()
    # lat = msg.latitude
    # lon = msg.longitude
    # # print (lat)
    # # print (lon)
    # # print(" ")
    # pub1.publish(lat)
    # pub2.publish(lon)
def distance(gps_msg):
    global R
    if gps_msg is None:
        return -1
    R=6371.0        #radius of earth
    # print(gps_msg.latitude)
    # print(gps_msg.longitude)
    lat1 = radians(gps_msg.latitude)
    lon1 = radians(gps_msg.longitude)
    lat2 = radians(goal_lat)
    lon2 = radians(goal_lon)

    dlon = lon2 - lon1
    dlat = lat2 - lat1

    a = sin(dlat / 2)**2 + cos(lat1) * cos(lat2) * sin(dlon / 2)**2
    c = 2 * atan2(sqrt(a), sqrt(1 - a))

    dist = R * c * 1000  # distance in meterst
    return dist  
    
def main():
    global goal_lat, goal_lon, sub, pub1
    goal_lat = 23.080685833
    goal_lon = 72.492187000
    rate = rospy.Rate(1.25)  # Adjust the rate as needed
    while not rospy.is_shutdown() and not terminate:
        print("entered")
        if sub is not None:
            sub.unregister()
        sub = rospy.Subscriber('/fix', NavSatFix,callbackGPS, queue_size=1)
        while not rospy.is_shutdown() and gps_msg is None:  # Wait until GPS data is available
            rate.sleep()
            print("check")
        sub.unregister()
        sub = rospy.Subscriber('/fix', NavSatFix, callbackGPS, queue_size=1)
        rate.sleep()
        print("present")
        sub.unregister()
        dist = distance(gps_msg)
        if(dist > 4):
            send.data[0] = 150
            send.data[1] = 1.0
        elif(dist < 4 and dist > 2):
            send.data[0] = dist*43.5
            send.data[1] = 1.0
        else:
            send.data[0] = 0
            send.data[1] = 1.0
		
        pub.publish(send)
        rate.sleep()

if __name__ == '__main__':
    main()
