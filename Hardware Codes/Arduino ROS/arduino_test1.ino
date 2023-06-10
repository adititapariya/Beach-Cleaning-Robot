
/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Empty.h>

ros::NodeHandle  nh;

float u;
void messageCb( const std_msgs::Float32 &toggle_msg){
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
  u = toggle_msg.data;
}

ros::Subscriber<std_msgs::Float32> sub("counter", messageCb );



std_msgs::Float32 msg1;
ros::Publisher chatter("chatter", &msg1);



void setup()
{
  pinMode(13, OUTPUT);
  nh.getHardware()->setBaud(115200);
  Serial.begin(115200);
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
}

void loop()
{
  msg1.data = u;
  chatter.publish( &msg1 );
  Serial.println(u);
  nh.spinOnce();
  delay(500);
}
