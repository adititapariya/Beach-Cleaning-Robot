#define echoPin 2
#define trigPin 3
int distance;
long duration;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(echoPin,INPUT);
 pinMode(trigPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034/2);
  Serial.print("Distance:");
  Serial.print(distance);
  Serial.println("cm");
  delay(1000);

}
