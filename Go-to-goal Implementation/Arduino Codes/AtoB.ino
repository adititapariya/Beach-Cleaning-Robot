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

int PWMR = 6;  //right motors
int DIRR = 7;
int PWML = 8;  //left motors
int DIRL = 9;
bool count = true;
ros::NodeHandle  nh;
std_msgs::Float64  msg1;
ros::Publisher pub("check",&msg1);
float distance;
void callback(const std_msgs::Float64 &msg){
     // blink the led
   distance = msg.data;
   //msg1.data = distance;
   pub.publish(&msg1);
   if(distance > 4){
    analogWrite(PWMR,175);   //forward
    digitalWrite(DIRR,LOW);  
    analogWrite(PWML,175);
    digitalWrite(DIRL,HIGH);  
    msg1.data = 1;
    pub.publish(&msg1); 
    }
    else if(distance < 4 && distance > 2){
    analogWrite(PWMR,distance*43.5);   //forward
    digitalWrite(DIRR,LOW);  
    analogWrite(PWML,distance*43.5);
    digitalWrite(DIRL,HIGH);
    msg1.data = 2;
    pub.publish(&msg1);   
    }
    else {
    analogWrite(PWMR,0);   //forward
    digitalWrite(DIRR,LOW);  
    analogWrite(PWML,0);
    digitalWrite(DIRL,HIGH);
    msg1.data = 3;   
    pub.publish(&msg1);
  }
}
ros::Subscriber<std_msgs::Float64> sub("dist", callback);




void setup()
{
  pinMode(PWMR,OUTPUT);
  pinMode(DIRR,OUTPUT); 
  pinMode(PWML,OUTPUT);
  pinMode(DIRL,OUTPUT);
  nh.getHardware()-> setBaud(57600);
  nh.initNode();
  nh.advertise(pub);
  nh.subscribe(sub);
}

void loop()
{
  if(count == true){
    delay(2000);
    count = false;
  }
  nh.spinOnce();
  /*if(distance > 4){
  analogWrite(PWMR,175);   //forward
  digitalWrite(DIRR,LOW);  
  analogWrite(PWML,175);
  digitalWrite(DIRL,HIGH);  
  msg1.data = 1;
  //pub.publish(&msg1); 
  }
  else if(distance < 4 && distance > 2){
  analogWrite(PWMR,distance*43.5);   //forward
  digitalWrite(DIRR,LOW);  
  analogWrite(PWML,distance*43.5);
  digitalWrite(DIRL,HIGH);
  msg1.data = 2;
  //pub.publish(&msg1);   
  }
  else {
  analogWrite(PWMR,0);   //forward
  digitalWrite(DIRR,LOW);  
  analogWrite(PWML,0);
  digitalWrite(DIRL,HIGH);
  msg1.data = 3;   
  //pub.publish(&msg1);
  }*/
}
