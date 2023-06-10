#include <EasyTransfer.h>
#include <Adafruit_PWMServoDriver.h>
#define EsptoMega Serial2

#define RXp2 17
#define TXp2 16

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

String incomingByte;
int PWMA = 6;    //Claw Planatary
int DIRA = 7;
int PWMB = 11;    //Vibration Planatary
int DIRB = 10;
int PWMD = 5;   //Conveyor Planatary
int DIRD = 9;
int i = 0;
int j = 0;

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
    analogWrite(PWMA,150);  //Claw starts 
    digitalWrite(DIRA, LOW);
    Serial.println("Claw");
  }
  int16_t up = psdata.up;
  if (up == 1){
    analogWrite(PWMA,0);    //Claw OFF
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
    for(i;i<1;i++){
    pwm.setPWM(7,0,240); //At channel 7, 600 is Pulselenght at 180 degree
    pwm.setPWM(11,0,240);
    delay(500);
    pwm.setPWM(7,0,170);  //to set servo again at flat level
    pwm.setPWM(11,0,170);
    delay(45);
  }
    i = 0;
  }
  int16_t right = psdata.right;
  if (right == 1){
    for(j;j<1;j++){
    pwm.setPWM(7,0,85); //At channel 7, 100 is Pulselength at zero degree position
    pwm.setPWM(11,0,85);
    delay(500);
    pwm.setPWM(7,0,170); //At channel 7, 600 is Pulselenght at 180 degree
    pwm.setPWM(11,0,170);
    delay(45);
  }
    j = 0;
  }
  int16_t cross = psdata.cross;
  if (cross == 1){
    analogWrite(PWMD,255);      //Conveyor Starts
    digitalWrite(DIRD,HIGH);
  }
  int16_t down = psdata.down;
  if (down == 1){
    analogWrite(PWMD,0);        //Conveyor OFF
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
