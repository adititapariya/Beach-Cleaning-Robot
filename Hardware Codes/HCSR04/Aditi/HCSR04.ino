#include<ros.h>
#include <HCSR04.h>
#include <std_msgs/Float32.h>
HCSR04 hc1(5, 4); //initialisation class HCSR04 (trig pin , echo pin)

void setup()
{   
    pinMode(5,INPUT);
    pinMode(4,OUTPUT);
    Serial.begin(9600);
}

void loop()
{   
    Serial.print("Distance1:");
    Serial.println(hc1.dist());  // return curent distance in serial
    delay(60);                 // we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.
}
