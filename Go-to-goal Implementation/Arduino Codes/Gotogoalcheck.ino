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
int c = 1;
int check = 1;
bool terminate1 = false;
bool terminate2 = false;
QMC5883L compass;
bool count = true;
ros::NodeHandle  nh;
std_msgs:: Float64MultiArray msg;
std_msgs::Float64  msg1;
std_msgs::String  msg2;
ros::Publisher pub("check",&msg1);
float distance;
void callback(const std_msgs::Float64MultiArray &msg){
     // blink the led
   distance = msg.data[0];
   //msg1.data = distance;
}

ros::Subscriber<std_msgs::Float64MultiArray> sub("dist", callback);
void orient(){
  float finalheading = 0.0;
  //Serial.println("Aaya 1");
  if(check == 1){
    finalheading = msg.data[1];
    check++;
  }
  int x,y,z;
  compass.read(&x,&y,&z);
  float heading = atan2(y, x);

  float declinationAngle = 0.00494;
  heading += declinationAngle;
  if(heading < 0)
    heading += 2*PI;

  if(heading > 2*PI)
    heading -= 2*PI;

  //Serial.print("Heading: ");
  //Serial.print(heading);
  float angle = finalheading - heading;
  float angle1;
  if(c==1){
    angle1=angle;
    c++;
  }
  // Serial.print("    Angle: ");
   //Serial.println(angle);
   if((angle1<3.14 && angle1>0)||(angle1<-3.14 && angle1>-6.28))
   {  
      if(angle> 0.07 && angle <= 3.14){
        analogWrite(PWMR,145);    //clockwise 
        digitalWrite(DIRR,HIGH);  
        analogWrite(PWML,145);
        digitalWrite(DIRL,HIGH);  
        }

   else if(angle < -3.14 && angle >= -6.28){
        analogWrite(PWMR,145);    //clockwise 
        digitalWrite(DIRR,HIGH);  
        analogWrite(PWML,145);
        digitalWrite(DIRL,HIGH); 
   }
         else {
        analogWrite(PWMR,0);
        digitalWrite(DIRR,HIGH);      
        analogWrite(PWML,0);
        digitalWrite(DIRL,HIGH);
        terminate1 = true;   
    }
   }
   else {
       if(angle >3.14 && angle<= 6.28){
        analogWrite(PWMR,145);    //anticlockwise 
        digitalWrite(DIRR,LOW);  
        analogWrite(PWML,145);
        digitalWrite(DIRL,LOW);
       }
        else if(angle < -0.07 && angle >= -3.14 ){
        analogWrite(PWMR,145);    //anticlockwise 
        digitalWrite(DIRR,LOW);  
        analogWrite(PWML,145);
        digitalWrite(DIRL,LOW); 
        }
         else {
        analogWrite(PWMR,0);
        digitalWrite(DIRR,HIGH);      
        analogWrite(PWML,0);
        digitalWrite(DIRL,HIGH);  
        terminate1 = true; 
    }
   }
}

void AtoB(){
 // Serial.println("Aaya 2");
  if(count == true){
    delay(2000);
    count = false;
  }
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
  terminate2 = true;
  }
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
  nh.spinOnce();
  if(!terminate1){
    orient();
    delay(10);
  }
  else if(!terminate2){
    AtoB();
    delay(10);
  }
  else {
  msg2.data = "khatam";
  pub.publish(&msg2);
  }
}
