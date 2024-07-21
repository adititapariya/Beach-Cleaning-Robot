#include <PS4Controller.h>
#include <analogWrite.h>

// the number of the LED pin
int PWM1 = 32;   //Front Right
int DIR1 = 19;
int PWM2 = 12;   //Front Left
int DIR2 = 27;
int PWM3 = 14;   //Back Right 
int DIR3 = 23; 
int PWM4 = 15;   //Back Left
int DIR4 = 4;
int PWM,TPWM;
//DIR high for forward 
void setup() {
  Serial.begin(115200);
  Serial.println("Ready.");
  pinMode(PWM1,OUTPUT);
  pinMode(DIR1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(DIR2,OUTPUT);
  pinMode(PWM3,OUTPUT);
  pinMode(DIR3,OUTPUT);
  pinMode(PWM4,OUTPUT);
  pinMode(DIR4,OUTPUT);

}
void loop(){
        analogWrite(PWM1,255);            
        digitalWrite(DIR1,LOW);
        analogWrite(PWM2,255);
        digitalWrite(DIR2,HIGH);
        analogWrite(PWM3,255);
        digitalWrite(DIR3,HIGH);  
        analogWrite(PWM4,255);
        digitalWrite(DIR4,LOW); 
}
