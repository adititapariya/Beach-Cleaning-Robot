/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */
#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float64.h>


ros::NodeHandle  nh;


std_msgs::Float64MultiArray gps1;



void messageCb( const std_msgs::Float64MultiArray &msg1){
   
   gps1.data = msg1.data;
  
}

ros::Subscriber<std_msgs::Float64MultiArray> sub("gps", &messageCb );

std_msgs::Float64MultiArray msg2;
   ros::Publisher chatter("chatter", &msg2);


void setup()
{
  nh.initNode();
  Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  nh.advertise(chatter);
  nh.subscribe(sub);
}

void loop()
{
//  msg2.data[0]=gps.data[0];
//  chatter.publish( &msg2 );
msg2.data=gps1.data;
 chatter.publish( &msg2 );
Serial.println(msg2.data[0]);
  nh.spinOnce();
  delay(500);
}
