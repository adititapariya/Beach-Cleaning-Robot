/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */
#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Empty.h>

ros::NodeHandle  nh;
std_msgs::Float64  msg1;
ros::Publisher pub("check",&msg1);
float distance,dist1;
void callback(const std_msgs::Float64 &msg){
     // blink the led
   distance = msg.data;
   dist1=distance;
   msg1.data = distance;
   pub.publish(&msg1);
}

ros::Subscriber<std_msgs::Float64> sub("dist", callback);




void setup()
{
  nh.getHardware()-> setBaud(57600);
  nh.initNode();
  nh.advertise(pub);
  nh.subscribe(sub);
}

void loop()
{
  
  nh.spinOnce();
}
