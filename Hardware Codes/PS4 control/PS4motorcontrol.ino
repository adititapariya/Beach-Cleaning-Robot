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
  if (PS4.isConnected()) {

     if (PS4.LStickY()) {
     Serial.printf("Left Stick x at %d\n", PS4.RStickY());
      if (PS4.LStickY()>=-5 && PS4.LStickY()<=5 ) {
        analogWrite(PWM1,0);
       analogWrite(PWM2,0);
      }
      else if(PS4.LStickY() > 5) {
        analogWrite(PWM1,(abs(PS4.LStickY()))* 2.0078);
        analogWrite(DIR1,0);
        analogWrite(PWM2,(abs(PS4.LStickY()))* 2.0078);
        analogWrite(DIR2,0);
      }
      else {
        analogWrite(PWM1,(abs(PS4.LStickY()))* 1.9921);
        analogWrite(DIR1,1);
        analogWrite(PWM2,(abs(PS4.LStickY()))* 1.9921);
        analogWrite(DIR2,1);
      }
    }
    
    if (PS4.RStickX()){
      Serial.printf("Right Stick x at %d\n", PS4.RStickX());
      if (PS4.RStickX()>=-5 && PS4.RStickX()<=5 ) {
        analogWrite(PWM1,0);
        analogWrite(PWM2,0);
      }
      else if(PS4.RStickX() > 5) {
        analogWrite(PWM1,(abs(PS4.RStickX()))* 2.0078);
        analogWrite(DIR1,0);
        analogWrite(PWM2,(abs(PS4.RStickX()))* 2.0078);
        analogWrite(DIR2,1);        
      }
      else {
        analogWrite(PWM1,(abs(PS4.RStickX()))* 1.9921);
        analogWrite(DIR1,1);
        analogWrite(PWM2,(abs(PS4.RStickX()))* 1.9921);
        analogWrite(DIR2,0); 
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
