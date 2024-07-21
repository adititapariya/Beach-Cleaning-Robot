#!/usr/bin/env python3
import math
import rospy
import time
from std_msgs.msg import Float64
from sensor_msgs.msg import NavSatFix
from std_msgs.msg import Float64MultiArray
from math import sin, cos, sqrt, atan2, radians

rospy.init_node('gps1')
pub1= rospy.Publisher('data', Float64MultiArray , queue_size = 10)  
terminate = False
sub = None
gps_msg = None
imu_msg= None

def callbackFinal(msg):
    global arr
    l = [msg.dist , msg.heading]
    arr = Float64MultiArray()
    arr.data = l
    print(arr)
    if(arr[1]>0.1)
    	pub1.publish(arr)
    
    elif
    	pub1.publish(msg.dist)

def orient(msg):
    global 
def callbackImu(msg):
    global imu_msg
    imu_msg = msg  
         
def callbackGPS(msg):
    global gps_msg
    gps_msg = msg
    print("Got GPS")
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
    global goal_lat, goal_lon, sub, pub1, arr , heading
    goal_lat = 21.17062900
    goal_lon = 72.78870700
    rate = rospy.Rate(1)  # Adjust the rate as needed
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
        print("present_dist")
        sub.unregister()
        dist = distance(gps_msg)
        sub = rospy.Subscriber('arimu', Float64 , callbackImu , queue_size=1)
        rate.sleep()
        print("present_heading")
        sub.unregister()
        heading = imu_msg
        l = [dist, heading]
        arr = Float64MultiArray()
        arr.data = l
        print(arr)
        pub1.publish(arr)
        rate.sleep()
        
if __name__ == '__main__':
    main()
