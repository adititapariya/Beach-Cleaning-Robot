#include <PS4Controller.h>
#include <analogWrite.h>
#include <EasyTransfer.h>

#define EsptoMega Serial2

EasyTransfer ED;

struct senddata{
  int16_t up;
  int16_t down;
  int16_t left;
  int16_t right;
  int16_t triangle;
  int16_t square;
  int16_t cross;
  int16_t circle;
};
senddata psdata;
// the number of the LED pin
int PWM1 = 32;   //Front Right
int DIR1 = 19;
int PWM2 = 12;   //Front Left
int DIR2 = 27;
int PWM3 = 14;      //Back Right 
int DIR3 = 23; 
int PWM4 = 15;      //Back Left
int DIR4 = 4;
int PWM,TPWM;
//DIR high for forward 
void setup() {
  Serial.begin(9600);
  EsptoMega.begin(9600,SERIAL_8N1,16,17);
  ED.begin(details(psdata),&EsptoMega);
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
    psdata.up = PS4.data.button.up;
    psdata.down = PS4.data.button.down;
    psdata.left = PS4.data.button.left;
    psdata.right = PS4.data.button.right;
    psdata.triangle = PS4.data.button.triangle;
    psdata.square = PS4.data.button.square;
    psdata.cross = PS4.data.button.cross;
    psdata.circle = PS4.data.button.circle;
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
              //Serial.println("Stop");
            }
            else if(PS4.RStickX() > 5) {                   //Turn Right 
              analogWrite(PWM1,TPWM);
              digitalWrite(DIR1,HIGH);
              analogWrite(PWM2,TPWM);
              digitalWrite(DIR2,LOW);  
              analogWrite(PWM3,TPWM);
              digitalWrite(DIR3,LOW);  
              analogWrite(PWM4,TPWM);
              digitalWrite(DIR4,LOW);   
              //Serial.println("Right");     
            }
            else {
              analogWrite(PWM1,TPWM);             //Turn Left
              digitalWrite(DIR1,LOW);
              analogWrite(PWM2,TPWM);
              digitalWrite(DIR2,HIGH);
              analogWrite(PWM3,TPWM);
              digitalWrite(DIR3,HIGH);  
              analogWrite(PWM4,TPWM);
              digitalWrite(DIR4,HIGH); 
              //Serial.println("Left");  
            }
          }
      }
      else if(PS4.LStickY() > 5) {        //Forward
        analogWrite(PWM1,PWM);
        Serial.println(PS4.LStickY());     
        digitalWrite(DIR1,LOW);
        analogWrite(PWM2,PWM);
        digitalWrite(DIR2,LOW);
        analogWrite(PWM3,PWM);
        digitalWrite(DIR3,HIGH);
        analogWrite(PWM4,PWM);
        digitalWrite(DIR4,LOW);
        //Serial.println("Forward");
      }
      else {
        analogWrite(PWM1,PWM);            //Backward
        Serial.println(PS4.LStickY());
        digitalWrite(DIR1,HIGH);
        analogWrite(PWM2,PWM);
        digitalWrite(DIR2,HIGH);
        analogWrite(PWM3,PWM);
        digitalWrite(DIR3,LOW);
        analogWrite(PWM4,PWM);
        digitalWrite(DIR4,HIGH);
        //Serial.println("Backward");
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
  ED.sendData(); 
  delay(50);
}
