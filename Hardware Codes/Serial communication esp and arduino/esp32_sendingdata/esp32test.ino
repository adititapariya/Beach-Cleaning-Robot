#define RXp2 16
#define TXp2 17

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXp2, TXp2);
}
void loop() {
  for (int i =0; i<301; i++)
  {
    Serial2.println(i);
    //Serial.println(Serial2.readString());
    Serial.print("sent packet ");Serial.println(i);
    delay(500);
    
  }
}
