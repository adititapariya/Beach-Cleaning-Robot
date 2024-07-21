float metalDetected;
int monitoring;
int metalDetection = 1;
int countRaw = 0;

void setup(){
Serial.begin(9600);
}

void loop(){
monitoring = analogRead(metalDetection);
metalDetected = (float) monitoring*100/1024.0;
Serial.println("Initializing Proximity Sensor");
delay(500);
Serial.println("Please wait..");
delay(1000);
Serial.print("Metal is Proximited = ");
Serial.println(metalDetected);
Serial.println("%");
if (monitoring > 250){
countRaw ++;
Serial.println("Metal is Detected");
Serial.print("Number of Detection > ");
Serial.println(countRaw);
delay(1000);
}
else{
  Serial.println("Other object detected");
}
}
