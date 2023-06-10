/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */
#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle  nh;

float u,v;
void messageCb( const geometry_msgs::Twist &msg1){
    u=msg1.linear.x;
    v=msg1.angular.z;// blink the led
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb );



geometry_msgs::Twist msg2;
ros::Publisher chatter("chatter", &msg2);


void setup()
{
  nh.initNode();
  nh.getHardware()->setBaud(115200);
  Serial.begin(115200);
  nh.advertise(chatter);
  nh.subscribe(sub);
}

void loop()
{
  msg2.linear.x = u;
  msg2.angular.z = v;
  chatter.publish( &msg2 );
  nh.spinOnce();
  delay(500);
}
