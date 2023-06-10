 #include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int i = 0;
void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog Servo motor works at 60 Hz frequency
}
//The servo level depends on value of Pulselength 
//Base/Flat level at 170
//Backward down at 85  (increaing this increases inclination)
//Forwward down at 240 (increaing this increases inclination)
void loop() {
  // Drive each PWM in a 'wave'
 // For backward movement
  for(i;i<1;i++){
      pwm.setPWM(7,0,85); //At channel 7, 100 is Pulselength at zero degree position
      pwm.setPWM(11,0,85);
      delay(500);  //adjust this delay so as to set angle by which servo will rotate
      pwm.setPWM(7,0,170); //At channel 7, 600 is Pulselenght at 180 degree
      pwm.setPWM(11,0,170);
      delay(350);
}
 //For forward movement
 for(i;i<1;i++){
      Serial.println(i);
      pwm.setPWM(7,0,170); 
      pwm.setPWM(11,0,170);
      delay(500); 
      pwm.setPWM(7,0,240); 
      pwm.setPWM(11,0,240);
      delay(350);
}
      pwm.setPWM(7,0,170);  //to set servo again at flat level
      pwm.setPWM(11,0,170);
}
  
  
