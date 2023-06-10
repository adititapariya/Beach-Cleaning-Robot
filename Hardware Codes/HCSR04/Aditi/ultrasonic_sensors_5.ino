#define echoPin1 A0
#define trigPin1 A1
#define echoPin2 A2
#define trigPin2 A3
#define echoPin3 A4
#define trigPin3 A5
#define echoPin4 4
#define trigPin4 3
#define echoPin5 7
#define trigPin5 5
int distance;
long duration;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(echoPin1,INPUT);
 pinMode(trigPin1,OUTPUT);
 pinMode(echoPin2,INPUT);
 pinMode(trigPin2,OUTPUT);
 pinMode(echoPin3,INPUT);
 pinMode(trigPin3,OUTPUT);
 pinMode(echoPin4,INPUT);
 pinMode(trigPin4,OUTPUT);
 pinMode(echoPin5,INPUT);
 pinMode(trigPin5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);

  duration=pulseIn(echoPin1,HIGH);
  distance=(duration*0.034/2);
  Serial.print("Distance1:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);

  digitalWrite(trigPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);

  duration=pulseIn(echoPin2,HIGH);
  distance=(duration*0.034/2);
  Serial.print("Distance2:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);

  digitalWrite(trigPin3,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3,LOW);

  duration=pulseIn(echoPin3,HIGH);
  distance=(duration*0.034/2);
  Serial.print("Distance3:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);

  digitalWrite(trigPin4,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4,LOW);

  duration=pulseIn(echoPin4,HIGH);
  distance=(duration*0.034/2);
  Serial.print("Distance4:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);

  digitalWrite(trigPin5,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin5,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin5,LOW);

  duration=pulseIn(echoPin5,HIGH);
  distance=(duration*0.034/2);
  Serial.print("Distance5:");
  Serial.print(distance);
  Serial.println("cm");
  delay(100);

}
