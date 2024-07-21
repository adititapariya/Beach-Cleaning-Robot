
#include <Wire.h>
#include <QMC5883L.h>

int PWMR = 12;  //right motors
int DIRR = 13;
int PWML = 8;  //left motors
int DIRL = 9;

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
    
  float headingDegrees = heading * 180/M_PI;
  Serial.print("    heading: ");
  Serial.print(heading);
  float finalheading = 0.767945;
  float angle = finalheading - heading;
  Serial.print("    angle: ");
  Serial.print(angle);
  Serial.println();
  if(angle > 0.307){
  analogWrite(PWMR,145);
  digitalWrite(DIRR,HIGH);      
  analogWrite(PWML,145);
  digitalWrite(DIRL,HIGH);  
    }
    else if(angle > 0.19 && angle < 0.307){
  analogWrite(PWMR,angle*471);
  digitalWrite(DIRR,HIGH);     
  analogWrite(PWML,angle*471);
  digitalWrite(DIRL,HIGH);  
    }
   else if(angle > 0.04 && angle < 0.19){
  analogWrite(PWMR,90);
  digitalWrite(DIRR,HIGH);      
  analogWrite(PWML,90);
  digitalWrite(DIRL,HIGH);   
    }
    else {
  analogWrite(PWMR,0);
  digitalWrite(DIRR,HIGH);      
  analogWrite(PWML,0);
  digitalWrite(DIRL,HIGH);   
    }

    return 0;
    delay(10);
    }
