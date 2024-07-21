#!/usr/bin/env python3
import math
import rospy

import time
from std_msgs.msg import Float64
from std_msgs.msg import Float64MultiArray
from sensor_msgs.msg import NavSatFix
from math import sin, cos, sqrt, atan2, radians

rospy.init_node('gps1')
#0 for PWM,1 for DIR,2 for function
#send[2] = 0.0 for orient
#send[2] = 1.0 for travel
#send[2] = 2.0 to end
#send[1] = 0.0 for clockwise in orient
#send[1] = 1.0 for anticlockwise in orient
#send[1] = 2.0 for forward
pub1= rospy.Publisher('dist', Float64MultiArray , queue_size = 10)  
terminate1 = False
terminate2 = False 
gps_msg = None
imu_msg = None
dlat = 0.0
dlon = 0.0
get = 1
angle = 0.0
checkheading = False
subimu = None
subgps = None
send = Float64MultiArray()
send.data = [0,0,0]
send.data[2] = 0
heading = 0.0
rate = None
A = 0.0

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

def callbackImu(msg):
    global heading,imu_msg,checkheading
    imu_msg = msg
    heading = msg.data
    checkheading = True
    print("Got IMU")

def calculate_angle():
    global dlat,dlon
    C = Float64()
    C = atan2(dlat,dlon)
    return C

def distance(gps_msg):
    global R,dlat,dlon
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
    dist = R * c * 1000  # distance in meters
    return dist
    
def travel():
    global terminate2,subgps
    print("Travel")
    if subgps is not None:
        subgps.unregister()
    subgps = rospy.Subscriber('/fix', NavSatFix,callbackGPS, queue_size=1)
    while not rospy.is_shutdown() and gps_msg is None:  # Wait until GPS data is available
        #rospy.sleep(0.001)
        rate.sleep()
        print("check")
    subgps.unregister()
    subgps = rospy.Subscriber('/fix', NavSatFix, callbackGPS, queue_size=1)
    #rospy.sleep(0.25)
    rate.sleep()
    print("present")
    subgps.unregister()
    dist = distance(gps_msg)
    print(dist)
    if(get == 1):
        print("return")
        return 0
    if(dist > 4):
        send.data[0] = 175        #forward
        send.data[1] = 2.0 
    elif(dist < 4 and dist > 2):
        send.data[0] = dist * 43.5  #forward
        send.data[1] = 2.0
    else:
        send.data[0] = 0
        send.data[1] = 2.0 
        send.data[2] = 2.0 
        terminate2 = True
        print("All done")
            
def orient():
    print("aaya")
    global angle,subimu,terminate1,get,checkheading,A,heading
    if(get == 1):
        travel()
        get = 2
        print(f"get:{get}")
        A = calculate_angle()
        print("A =",A)
        print("1st call")
    if subimu is not None:
        subimu.unregister()
    subimu = rospy.Subscriber('arimu', Float64 , callbackImu , queue_size=1)
    while not rospy.is_shutdown() and imu_msg is None:              # Wait until GPS data is available
        #rospy.sleep(0.001)
        pub1.publish(send)
        rate.sleep()
        print("check2")
    subimu.unregister()   
    subimu = rospy.Subscriber('arimu', Float64 , callbackImu , queue_size=1)
    while not rospy.is_shutdown() and (checkheading == False):         
        pub1.publish(send) 
        rate.sleep()
        print("check3")
    subimu.unregister() 
    print("heading =",heading)
    angle = A - heading
    print("Orient")
    #cases of angle and publish 
    print(angle1)
    checkheading = False
    if angle > 0.07 and angle <= 3.14:
        print(angle)
        send.data[0] = 120        #anticlockwise 
        send.data[1] = 1.0 
    elif angle > 3.14 and angle <= 6.28:
        send.data[0] = 120        #clockwise 
        send.data[1] = 0.0 
    elif angle < -0.07 and angle >= -3.14:
        send.data[0] = 120        #clockwise 
        send.data[1] = 0.0     
    elif angle < -3.14 and angle >= -6.28:
        send.data[0] = 120        #anticlockwise 
        send.data[1] = 1.0 
    else:
        send.data[0] = 0
        send.data[1] = 1.0
        send.data[2] = 1.0  
        terminate1 = True
        print("Orient done")

def main():
    global goal_lat, goal_lon,pub1,rate,terminate1,terminate2
    goal_lat = 21.166949666
    goal_lon = 72.784780000
    rate = rospy.Rate(0.8)  # Adjust the rate as needed
    while not rospy.is_shutdown() and not terminate1:
        orient()
        print("idhar bey")
        rate.sleep()
        pub1.publish(send)
        print(terminate1)
    while not rospy.is_shutdown() and not terminate2:
        travel()
        rate.sleep()
        pub1.publish(send)
    
if __name__ == '__main__':
#rospy.init_node('gps1')
#pub1 = rospy.Publisher('dist', Float64MultiArray, queue_size=10)
    main()

