/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */
#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/Float64.h>


ros::NodeHandle nh;

float lat1,lon1;
//std_msgs::Float64 lon;
void messageCb( const std_msgs::Float64 &msg1){
   lat1= msg1.data;
}

void messageCb1( const std_msgs::Float64 &msg2){
   lon1= msg2.data;
}

ros::Subscriber<std_msgs::Float64> sub("lat", &messageCb );
ros::Subscriber<std_msgs::Float64> sub2("lon", &messageCb1 );


std_msgs::Float64 msg3;
std_msgs::Float64 msg4;
   ros::Publisher chatter1("chatter1", &msg3);
   ros::Publisher chatter2("chatter2", &msg4);

void setup()
{
  nh.initNode();
  nh.getHardware()->setBaud(115200);
  Serial.begin(115200);
  nh.advertise(chatter1);
  nh.advertise(chatter2);
  nh.subscribe(sub);
  nh.subscribe(sub2);
}

void loop()
{
 msg3.data=lat1;
 msg4.data=lon1;
 chatter2.publish( &msg4 );
 chatter1.publish( &msg3 );
// Serial.println (lat1);
  nh.spinOnce();
  delay(500);
}
