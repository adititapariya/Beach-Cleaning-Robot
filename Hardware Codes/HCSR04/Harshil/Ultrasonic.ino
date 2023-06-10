int trig =5;
int echo = 6;
long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig,LOW);
delay(0.002);
digitalWrite(trig,HIGH);
delay(0.01);
digitalWrite(trig,LOW);
duration = pulseIn(echo,HIGH);
distance = duration * (0.034/2);
Serial.println("Distance =");
Serial.println(distance);
delay(20);
}
