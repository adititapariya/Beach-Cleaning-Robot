#include <Wire.h>
#include <QMC5883L.h>

int PWMR = 12;  //right motors
int DIRR = 13;
int PWML = 8;  //left motors
int DIRL = 9;
int count=1;
QMC5883L compass;

void setup() {
  // put your setup code here, to run once:
  pinMode(PWMR,OUTPUT);
  pinMode(DIRR,OUTPUT);
  pinMode(PWML,OUTPUT);
  pinMode(DIRL,OUTPUT);
  Wire.begin();
  Serial.begin(9600);
  compass.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  int x,y,z;
  compass.read(&x,&y,&z);
  float heading = atan2(y, x);

  float declinationAngle = 0.00494;
  heading += declinationAngle;
  if(heading < 0)
    heading += 2*PI;

  if(heading > 2*PI)
    heading -= 2*PI;

   Serial.print("Heading: ");
  Serial.print(heading);
  float finalheading = 3.0;
  float angle = finalheading - heading;
  float angle1;
  if(count==1){
    angle1=angle;
    count++;
  }
  
   Serial.print("    Angle: ");
   Serial.println(angle);
   if((angle1<3.14 && angle1>0)||(angle1<-3.14 && angle1>-6.28))
   {
      if(angle> 0.05 && angle <= 3.14){
        analogWrite(PWMR,145);    //clockwise 
        digitalWrite(DIRR,HIGH);  
        analogWrite(PWML,145);
        digitalWrite(DIRL,HIGH);  
        }

   else if(angle < -3.14 && angle >= -6.28){
        analogWrite(PWMR,145);    //clockwise 
        digitalWrite(DIRR,HIGH);  
        analogWrite(PWML,145);
        digitalWrite(DIRL,HIGH); 
   }
         else {
        analogWrite(PWMR,0);
        digitalWrite(DIRR,HIGH);      
        analogWrite(PWML,0);
        digitalWrite(DIRL,HIGH);   
    }
   }
   else {
       if(angle >3.14 && angle<= 6.28){
        analogWrite(PWMR,145);    //anticlockwise 
        digitalWrite(DIRR,LOW);  
        analogWrite(PWML,145);
        digitalWrite(DIRL,LOW);
       }
        else if(angle < -0.05 && angle >= -3.14 ){
        analogWrite(PWMR,145);    //anticlockwise 
        digitalWrite(DIRR,LOW);  
        analogWrite(PWML,145);
        digitalWrite(DIRL,LOW); 
        }
         else {
        analogWrite(PWMR,0);
        digitalWrite(DIRR,HIGH);      
        analogWrite(PWML,0);
        digitalWrite(DIRL,HIGH);   
    }
   }
    delay(10);
}
