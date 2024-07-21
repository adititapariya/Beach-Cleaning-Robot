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
int PWMD = 5;   //Conveyor Planatary
int DIRD = 9;

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
void rotateLeft() {
  Serial.println("left gone");
  pwm.setPWM(7,0,360);
  delay(1000);
  pwm.setPWM(7,0,480);
  delay(1000);
  
for (int pulse=480;pulse>=335;pulse -=10){
    pwm.setPWM(7,0,pulse);
    delay(50);
  }
}
void rotateRight() {
 Serial.println("right gone");
 pwm.setPWM(7,0,360);
 delay(1000);
 pwm.setPWM(7,0,210);
 delay(1000);
for (int pulse=210;pulse<=335;pulse +=10){
    pwm.setPWM(7,0,pulse);
    delay(50);
  }
  pwm.setPWM(7,0,360);
  delay(1000);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  EsptoMega.begin(9600);
  ED.begin(details(psdata),&EsptoMega);
  Serial2.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(PWMD, OUTPUT);
  pinMode(DIRD,OUTPUT);
}
void loop() {

  if (EsptoMega.available()){
    ED.receiveData();
  }
  
  int16_t triangle = psdata.triangle;
  if (triangle == 1){
    analogWrite(PWMA,80);  //Claw starts 
    digitalWrite(DIRA,LOW);
    Serial.println("Claw");
  }
  int16_t up = psdata.up;
  if (up == 1){
    analogWrite(PWMA,0);    //Claw OFF
  }
  int16_t cross = psdata.cross;
  if (cross == 1){
    analogWrite(PWMA,80);  //Claw reverse 
    digitalWrite(DIRA,HIGH);
    Serial.println("Claw");
  }
  int16_t square = psdata.square;
  if (square == 1){
    analogWrite(PWMB, 150);     //Vibration starts
    digitalWrite(DIRB,HIGH);
    Serial.println("Vibration");
  }
  int16_t left = psdata.left;   
  if (left == 1){
    analogWrite(PWMB,0);      //Vibration OFF
  }
  int16_t circle = psdata.circle;
  if (circle == 1){
   rotateLeft();
   Serial.println("Servo Right");
  }
  int16_t right = psdata.right;
  if (right == 1){
    rotateRight();
    Serial.println("Servo Left");
  }
 
  Serial.print(psdata.up);
  Serial.print(' ');
  Serial.print(psdata.down);
  Serial.print(' ');
  Serial.print(psdata.left);
  Serial.print(' ');
  Serial.print(psdata.right);
  Serial.print(' ');
  Serial.print(psdata.triangle);   
  Serial.print(" ");
  Serial.print(psdata.square);   
  Serial.print(" ");
  Serial.print(psdata.cross);   
  Serial.print(" ");
  Serial.print(psdata.circle);   
  Serial.print(" ");
  Serial.println();
  delay(50);
}
