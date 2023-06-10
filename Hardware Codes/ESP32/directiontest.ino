#include <PS4Controller.h>
#include <analogWrite.h>

// the number of the LED pin
int PWM1 = 13;   //right motors
int DIR1 = 27;
int PWM2 = 15;   //left motors
int DIR2 = 4;

void setup() {
  Serial.begin(115200);
  PS4.begin("4c:d5:77:df:cf:64");
  Serial.println("Ready.");
  pinMode(PWM1,OUTPUT);
  pinMode(DIR1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(DIR2,OUTPUT);

}
void loop(){
  // Below has all accessible outputs from the controller
  
        analogWrite(PWM1,255);
        analogWrite(DIR1,0);
        analogWrite(PWM2,255);
        analogWrite(DIR2,0);   ///backwards
        analogWrite(PWM1,255);
        digitalWrite(DIR1,HIGH);
        analogWrite(PWM2,255);
        digitalWrite(DIR1,HIGH); //forward
      }
