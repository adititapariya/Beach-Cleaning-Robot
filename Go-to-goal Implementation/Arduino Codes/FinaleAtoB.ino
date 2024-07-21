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

int PWM1 = 32;   //Front Right
int DIR1 = 19;
int PWM2 = 12;   //Front Left
int DIR2 = 27;
int PWM3 = 14;      //Back Right 
int DIR3 = 23; 
int PWM4 = 15;      //Back Left
int DIR4 = 4;
int PWM;
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
        PWM = 165;
        analogWrite(PWM1,PWM);     
        digitalWrite(DIR1,LOW);
        analogWrite(PWM2,PWM);
        digitalWrite(DIR2,LOW);
        analogWrite(PWM3,PWM);
        digitalWrite(DIR3,HIGH);
        analogWrite(PWM4,PWM);
        digitalWrite(DIR4,LOW); 
    msg1.data = 1;
    pub.publish(&msg1); 
    }
    else if(distance < 4 && distance > 2){
    PWM = distance*43.5;
        analogWrite(PWM1,PWM);   
        digitalWrite(DIR1,LOW);
        analogWrite(PWM2,PWM);
        digitalWrite(DIR2,LOW);
        analogWrite(PWM3,PWM);
        digitalWrite(DIR3,HIGH);
        analogWrite(PWM4,PWM);
        digitalWrite(DIR4,LOW);
    msg1.data = 2;
    pub.publish(&msg1);   
    }
    else {
        analogWrite(PWM1,0);   
        digitalWrite(DIR1,LOW);
        analogWrite(PWM2,0);
        digitalWrite(DIR2,LOW);
        analogWrite(PWM3,0);
        digitalWrite(DIR3,HIGH);
        analogWrite(PWM4,0);
        digitalWrite(DIR4,LOW);
    msg1.data = 3;   
    pub.publish(&msg1);
  }
}
ros::Subscriber<std_msgs::Float64> sub("dist", callback);




void setup()
{
  pinMode(PWM1,OUTPUT);
  pinMode(DIR1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(DIR2,OUTPUT);
  pinMode(PWM3,OUTPUT);
  pinMode(DIR3,OUTPUT);
  pinMode(PWM4,OUTPUT);
  pinMode(DIR4,OUTPUT);
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
