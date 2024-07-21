#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Empty.h>
#include <Wire.h>
#include <QMC5883L.h>

int PWMR = 12;  //right motors
int DIRR = 13;
int PWML = 8;  //left motors
int DIRL = 9;
int PWM = 0;
int dirl = 0;
int dirr = 0;
int c = 1;
QMC5883L compass;
ros::NodeHandle  nh;
std_msgs::Float64  msg1;
std_msgs::Float64MultiArray msg,received_msg;
std_msgs::String  msg2;
ros::Publisher pub("arimu",&msg1);
float distance;
void callback(const std_msgs::Float64MultiArray &received_msg){
     // blink the led
     msg = received_msg;
     if(msg.data[2] == 0){
         orient();
       // nh.spinOnce();
     }
     else if(msg.data[2] == 1){
       //nh.spinOnce();
        AtoB();
     }
     else {
      msg2.data = "khatam bc";
      pub.publish(&msg2);
}
}

ros::Subscriber<std_msgs::Float64MultiArray> sub("dist", callback);
void orient(){
  if(msg.data[2] == 1.0 || msg.data[2] == 2.0){
    return;
  }
  //Serial.println("Aaya 1");
  int x,y,z;
  compass.read(&x,&y,&z);
  float heading = atan2(y, x);

  float declinationAngle = 0.00494;
  heading += declinationAngle;
  /*if(heading < 0)
    heading += 2*PI;

  if(heading > 2*PI)
    heading -= 2*PI;*/
  msg1.data = heading;
  pub.publish(&msg1);
  //nh.spinOnce();
  //set PWM & DIR
  PWM = msg.data[0];
  if(msg.data[1] == 0.0){
    dirl = HIGH;     //clockwise
    dirr = HIGH;
  }
  else if(msg.data[1] == 1.0){
    dirl = LOW;     //anticlockwise
    dirr = LOW;
}
}

void AtoB(){
  //set PWM & DIR values
  //nh.spinOnce();
  PWM = msg.data[0];
  dirr = LOW;
  dirl = HIGH;
  delay(250);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PWMR,OUTPUT);
  pinMode(DIRR,OUTPUT);
  pinMode(PWML,OUTPUT);
  pinMode(DIRL,OUTPUT);
  Wire.begin();
  //Serial.begin(57600);
  compass.init();
  nh.getHardware()-> setBaud(57600);
  nh.initNode();
  nh.advertise(pub);
  nh.subscribe(sub);
}

void loop() {
  // put your main code here, to run repeatedly:
  //PWM & DIR 
  nh.spinOnce();
  analogWrite(PWMR,PWM);   //forward
  digitalWrite(DIRR,dirr);  
  analogWrite(PWML,PWM);
  digitalWrite(DIRL,dirl);
}
