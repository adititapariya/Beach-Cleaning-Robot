/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <geometry_msgs/Twist.h>
ros::NodeHandle  nh;


geometry_msgs::Twist str_msg;
geometry_msgs::Twist toggle_msg;
ros::Publisher chatter("chatter", &str_msg);

void messageCb(const geometry_msgs::Twist &toggle_msg )
{
    str_msg=toggle_msg;
    chatter.publish(&str_msg); 
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb );

void setup()
{ 
  Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  nh.initNode();
 nh.advertise(chatter);
  nh.subscribe(sub);
}

void loop()
{  
///
  nh.spinOnce();
  delay(1);
}
