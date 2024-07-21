
#include <HCSR04.h>

HCSR04 hc1(17,16);    //Right
HCSR04 hc2(25,27);    //Right Slant
HCSR04 hc3(51,53);    //Front 
HCSR04 hc4(A13,A14);  //Left Slant
HCSR04 hc5(A10,A9);   //Left

int PWMR = 8;  //right motors
int DIRR = 10;
int PWML = 4;  //left motors
int DIRL = 5;

void setup()
{
  pinMode(PWMR,OUTPUT);
  pinMode(DIRR,OUTPUT); 
  pinMode(PWML,OUTPUT);
  pinMode(DIRL,OUTPUT);
  Serial.begin(9600);
}

void loop()  
{
 float l = hc1.dist();
 float LS = hc2.dist();
 float F = hc3.dist();
 float RS = hc4.dist();
 float r = hc5.dist();
 if(F >= 40 && LS >= 40 && RS >= 40){      //forward
  analogWrite(PWMR,175);
  digitalWrite(DIRR,LOW);     
  analogWrite(PWML,175);
  digitalWrite(DIRL,HIGH);  
}
   
else if((F < 40 && RS >= 40 && r >= 25) || (l < 40 && r >= 25 && RS < 40) ||  (LS < 40 && r >= 25)){ // Right (Slight right)
  analogWrite(PWMR,255);
  digitalWrite(DIRR,LOW);      
  analogWrite(PWML,255);
  digitalWrite(DIRL,LOW);  
}
     
else if((LS >= 40 && l >= 25 && RS < 40) || (l >= 25 && F < 40 && r < 25) || (l >= 25 && r < 25 && LS < 40)){ //Left (Slight left)
  analogWrite(PWMR,255);
  digitalWrite(DIRR,HIGH);     
  analogWrite(PWML,255);
  digitalWrite(DIRL,HIGH); 
}
else {// backwards 

     Serial.println("elsecase");
     analogWrite(5,0);
     digitalWrite(4,LOW);
     analogWrite(9,0);
     digitalWrite(8,LOW);
     delay(100);
     analogWrite(PWMR,175);
     digitalWrite(DIRR,HIGH);     
     analogWrite(PWML,175);
     digitalWrite(DIRL,LOW); 
}
delay(50);

}
