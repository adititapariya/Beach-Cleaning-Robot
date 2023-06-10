/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  PWM test - this will drive 16 PWMs in a 'wave'

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
 
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);
#define SERVOMIN 150
#define SERVOMAX 600


void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog Servo motor works at 60 Hz frequency
}

void loop() {
  // Drive each PWM in a 'wave'
  
      pwm.setPWM(7, 0, 100); //At channel 7, 100 is Pulselength at zero degree position
      delay(1000);  //adjust this delay so as to set angle by which servo will rotate
      pwm.setPWM(7, 0, 600); //At channel 7, 600 is Pulselenght at 180 degree
      delay(1000);
  }
  // Values can be tuned between 100 to 200 or bit more at 0 degree position and 550 to 600 or more at 180 degree position to tune speed.
