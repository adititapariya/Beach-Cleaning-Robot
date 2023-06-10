
#include <HCSR04.h>
#define LM1 5 //left motor
#define LM2 4 //left motor
#define RM1 2 //right motor
#define RM2 3 //right motor

HCSR04 hc1(9,8); //right
HCSR04 hc2(5,7);//front
HCSR04 hc3(3,2);//left

float LS,F,RS;

void setup()
{
 pinMode(LM1,OUTPUT);
 pinMode(LM2,OUTPUT);
 pinMode(RM1,OUTPUT);
 pinMode(RM2,OUTPUT);
  Serial.begin(9600);
}

void loop()      //check for >= conditions if error found
{
  int i;
  LS = hc1.dist();
  F = hc2.dist();
  RS = hc3.dist();


if(F >= 40 && LS >= 40 && RS >= 40){      //forward
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);

}
   
else if(LS < 40 && RS >= 40){ // right
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);;
}
     
else if(LS >= 40 && (RS < 40 || F < 40)){    //left
    digitalWrite(LM1, LOW);
    digitalWrite(LM2 , HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);

}
else {                        // backwards (might have error)
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);

}
Serial.print("Distance1:");
Serial.println(hc1.dist());
Serial.print("Distance2:");
Serial.println(hc2.dist());
Serial.print("Distance3:");
Serial.println(hc3.dist());
delay(50);
}
