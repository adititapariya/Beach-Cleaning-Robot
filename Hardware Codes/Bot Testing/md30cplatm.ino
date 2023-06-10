int PWM = 5;
int DIR = A3;
void setup() {
  // put your setup code here, to run once:
pinMode(PWM,OUTPUT);
pinMode(DIR,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
analogWrite(PWM,250);
//analogWrite(PWM,150);  //150 for vibration mechanism
//analogWrite(PWM,150);  //150 for claw picking mechanism
//digitalWrite(DIR,LOW);  backward for claw
digitalWrite(DIR,LOW);  //forward 
}
