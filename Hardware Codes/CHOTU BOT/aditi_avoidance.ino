#include <HCSR04.h>
HCSR04 hc1(23,25);
HCSR04 hc2(27,29);
HCSR04 hc3(31,33);
HCSR04 hc4(39,41);
HCSR04 hc5(43,45);

#define mpwm1 8
#define mdir1 9
#define mpwm2 10 
#define mdir2 11

int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(mpwm1, OUTPUT);
  pinMode(mdir1, OUTPUT);
  pinMode(mpwm2, OUTPUT);
  pinMode(mdir2, OUTPUT);
}

void loop() {
  
  // put your main code here, to run repeatedly:
 float L,F,R,LS,RS;
  L = hc1.dist();
  LS = hc2.dist();
  F = hc3.dist();
  RS = hc4.dist();
  R = hc5.dist();




 delay(60);


if(F >= 25 && LS >= 25 && RS >= 25){      //forward
     analogWrite(8,180);
     digitalWrite(9,LOW);
     analogWrite(10,180);
     digitalWrite(11,HIGH); 
     i=0;
}
   
else if((F < 25 && RS >= 25 && R >= 15) || (LS < 25 && F >= 25 && RS >= 25) || (L < 15 && F < 25 && R >= 15) || (L < 15 && LS < 25 && R >= 15)){ // right
     analogWrite(8,180);
     digitalWrite(9,LOW);
     analogWrite(10,180);
     digitalWrite(11,LOW);
     i=0;
}
     
else if((LS >= 25 && F >= 25 && RS < 25) || (L >= 15 && RS < 25 && R < 15) || (L >= 15 && F < 25 && R < 15) || (L >= 15 && F < 25 && RS < 25)){    //left
     analogWrite(8,180);
     digitalWrite(9,HIGH);
     analogWrite(10,180);
     digitalWrite(11,HIGH);
     i=0;
}
else {// backwards 
     if(i==0){
     analogWrite(8,0);
     digitalWrite(9,HIGH);
     analogWrite(10,0);
     digitalWrite(11,LOW);
     i++;
     }
    
     delay(10);
     analogWrite(8,180);
     digitalWrite(9,LOW);
     analogWrite(10,180);
     digitalWrite(11,LOW); 
}
delay(50);
  

}
