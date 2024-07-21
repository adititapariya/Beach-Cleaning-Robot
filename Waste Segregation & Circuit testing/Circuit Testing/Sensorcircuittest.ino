
#include <HCSR04.h>

HCSR04 hc1(25,27); 
HCSR04 hc2(17,16);
HCSR04 hc3(51,53);
HCSR04 hc4(A13,A14);
HCSR04 hc5(A10,A9);   

void setup()
{
  Serial.begin(9600);
}

void loop()  
{
Serial.print("Distance1:");
Serial.println(hc1.dist());
Serial.print("Distance2:");
Serial.println(hc2.dist());
Serial.print("Distance3:");
Serial.println(hc3.dist());
Serial.print("Distance4:");
Serial.println(hc4.dist());
Serial.print("Distance5:");
Serial.println(hc5.dist());
delay(20);
}
