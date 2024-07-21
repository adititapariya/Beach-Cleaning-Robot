/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */
#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Empty.h>
#include <EasyTransfer.h>
#include <Adafruit_PWMServoDriver.h>
#define EsptoMega Serial2

#define RXp2 17
#define TXp2 16

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

String incomingByte;
int PWMA = 7;    //Claw Planatary
int DIRA = 6;
int PWMB = 11;    //Vibration Planatary
int DIRB = 10;



//create object
EasyTransfer ET; 
struct SEND_DATA_STRUCTURE{
  //put your variable definitions here for the data you want to send
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  float PWME;
  float DIRE;
};

SEND_DATA_STRUCTURE mydata;

EasyTransfer ED;

struct receivedata{
  int16_t up;
  int16_t down;
  int16_t left;
  int16_t right;
  int16_t triangle;
  int16_t square;
  int16_t cross;
  int16_t circle; 
};

receivedata psdata;
bool count = true;
bool subscribe = false;
ros::NodeHandle  nh;
std_msgs:: Float64MultiArray msg,received_msg;
std_msgs::Float64  msg1;
ros::Publisher pub("check",&msg1);
float distance;
void callback(const std_msgs::Float64MultiArray &received_msg){
     // blink the led
   msg = received_msg;
   if(subscribe){
   msg1.data = 7;
   pub.publish(&msg1);
   mydata.PWME = msg.data[0];
   mydata.DIRE = msg.data[1];
   ET.sendData();
   }
   else {
    mydata.PWME = 0;
    mydata.DIRE = 0;
    msg1.data = 1;
    pub.publish(&msg1);
   }
}
ros::Subscriber<std_msgs::Float64MultiArray> sub("dist", callback);

void rotateLeft() {
  //Serial.println("left gone");
  pwm.setPWM(7,0,360);
  delay(1000);
  pwm.setPWM(7,0,480);
  delay(1000);
  
  for (int pulse=480;pulse>=360;pulse -=5){
    pwm.setPWM(7,0,pulse);
    delay(50);
  }
}
void rotateRight() {
 //Serial.println("right gone");
 pwm.setPWM(7,0,360);
 delay(1000);
 pwm.setPWM(7,0,260);
 delay(1000);
for (int pulse=260;pulse<=360;pulse +=5){
    pwm.setPWM(7,0,pulse);
    delay(50);
  }
  pwm.setPWM(7,0,360);
  delay(1000);
}
void setup()
{
  //Serial.begin(57600);
  EsptoMega.begin(57600);
  ED.begin(details(psdata),&EsptoMega);
  Serial2.begin(57600);
  pwm.begin();
  pwm.setPWMFreq(60);
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA,OUTPUT); 
  pinMode(PWMB, OUTPUT);
  pinMode(DIRB,OUTPUT);
  nh.getHardware()-> setBaud(57600);
  nh.initNode();
  nh.advertise(pub);
  nh.subscribe(sub);
  ET.begin(details(mydata), &Serial);
  randomSeed(analogRead(0));
}

void loop()
{
  if (EsptoMega.available()){
    ED.receiveData();
  }
  if (psdata.down == 1) {
    subscribe = true;
    //Serial.print("Subscribe: ");
    //Serial.println(subscribe);
  }
  if(psdata.cross == 1){
    subscribe = false;
  }
  if(subscribe){
    if(count == true){
    delay(2000);
    count = false;
  }
  }
  else {
    //Serial.println("Not Subscribed");
    int16_t triangle = psdata.triangle;
  if (triangle == 1){
    analogWrite(PWMA,80);  //Claw starts 
    digitalWrite(DIRA,LOW);
    //Serial.println("Claw");
  }
  int16_t up = psdata.up;
  if (up == 1){
    analogWrite(PWMA,0);    //Claw OFF
  }
  int16_t square = psdata.square;
  if (square == 1){
    analogWrite(PWMB, 150);     //Vibration starts
    digitalWrite(DIRB,HIGH);
    //Serial.println("Vibration");
  }
  int16_t left = psdata.left;   
  if (left == 1){
    analogWrite(PWMB,0);      //Vibration OFF
  }
  int16_t circle = psdata.circle;
  if (circle == 1){
   rotateRight();
   //Serial.println("Servo Right");
  }
  int16_t right = psdata.right;
  if (right == 1){
    rotateLeft();
   // Serial.println("Servo Left");
  }
  nh.spinOnce();
  }
 
}
