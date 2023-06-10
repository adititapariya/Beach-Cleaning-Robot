#include <PS4Controller.h>
#include <analogWrite.h>

// the number of the LED pin
int PWM1 = 32;   //Front Right
int DIR1 = 19;
int PWM2 = 12;   //Front Left
int DIR2 = 27;
int PWM3 = 13;      //Back Right 
int DIR3 = 23; 
int PWM4 = 15;      //Back Left
int DIR4 = 4;
int PWM,TPWM;
//DIR high for forward 
void setup() {
  Serial.begin(115200);
  PS4.begin("4c:d5:77:df:cf:64");
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
  // Below has all accessible outputs from the controller
  if (PS4.isConnected()) {
     if (PS4.LStickY()) {
     PWM = int((abs(PS4.LStickY()))* 2.0078);
     Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      if (PS4.LStickY()>=-5 && PS4.LStickY()<=5 ) {
             if (PS4.RStickX()){
            TPWM = int((abs(PS4.RStickX()))* 2.0078);
            Serial.printf("Right Stick x at %d\n", PS4.RStickX());
            if (PS4.RStickX()>=-5 && PS4.RStickX()<=5 ) {
              analogWrite(PWM1,0);
              analogWrite(PWM2,0);
              analogWrite(PWM3,0);
              analogWrite(PWM4,0);
            }
            else if(PS4.RStickX() > 5) {                                      //Turn Right
              analogWrite(PWM1,TPWM);
              digitalWrite(DIR1,LOW);
              analogWrite(PWM2,TPWM);
              digitalWrite(DIR2,HIGH);  
              analogWrite(PWM3,TPWM);
              digitalWrite(DIR3,LOW);  
              analogWrite(PWM4,TPWM);
              digitalWrite(DIR4,HIGH);        
            }
            else {
              analogWrite(PWM1,TPWM);             //Turn Left
              digitalWrite(DIR1,HIGH);
              analogWrite(PWM2,TPWM);
              digitalWrite(DIR2,LOW);
              analogWrite(PWM3,TPWM);
              digitalWrite(DIR3,HIGH);  
              analogWrite(PWM4,TPWM);
              digitalWrite(DIR4,LOW);   
            }
          }
      }
      else if(PS4.LStickY() > 5) {                                 //Forward
        analogWrite(PWM1,PWM);
        Serial.println(PS4.LStickY());     
        digitalWrite(DIR1,HIGH);
        analogWrite(PWM2,PWM);
        digitalWrite(DIR2,HIGH);
        analogWrite(PWM3,PWM);
        digitalWrite(DIR3,HIGH);
        analogWrite(PWM4,PWM);
        digitalWrite(DIR4,HIGH);
      }
      else {
        analogWrite(PWM1,PWM);            //Backward
        Serial.println(PS4.LStickY());
        digitalWrite(DIR1,LOW);
        analogWrite(PWM2,PWM);
        digitalWrite(DIR2,LOW);
        analogWrite(PWM3,PWM);
        digitalWrite(DIR3,LOW);
        analogWrite(PWM4,PWM);
        digitalWrite(DIR4,LOW);
      }
    }
     
    if (PS4.Charging()) Serial.println("The controller is charging");
    if (PS4.Audio()) Serial.println("The controller has headphones attached");
    if (PS4.Mic()) Serial.println("The controller has a mic attached");

    Serial.printf("Battery Level : %d\n", PS4.Battery());

    Serial.println();
    // This delay is to make the output more human readable
    // Remove it when you're not trying to see the output
    
  }
}
