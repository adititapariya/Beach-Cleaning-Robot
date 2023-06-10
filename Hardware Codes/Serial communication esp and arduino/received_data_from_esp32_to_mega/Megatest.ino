#define RXp2 17
#define TXp2 16
String incomingByte;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(115200);
}
void loop() {
   char data[100] = {0};
   if (Serial2.available())
   { 
    Serial2.readBytesUntil('\n',data,100);
    Serial.print("Received: ");
    Serial.println(data);
    delay(2000);
   }
   else
   {
    Serial.println("Nothing in the buffer... still waiting to receive...");
    delay (5000);
   }
}
