/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Empty.h>
int trig =5;
int echo = 6;
long duration;
long distance;

ros::NodeHandle  nh;


std_msgs::Float32 flt_msg;
ros::Publisher chatter("chatter", &flt_msg);

void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(57600);
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{ 
  digitalWrite(trig,LOW);
  delay(0.002);
  digitalWrite(trig,HIGH);
  delay(0.025);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = duration * (0.034/2);
  flt_msg.data = distance;
  chatter.publish(&flt_msg);
  nh.spinOnce();
  Serial.println("Distance =");
  Serial.println(distance);
  delay(100);
}
