#define RXp2 16
#define TXp2 17
int a = 5;
void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
}
void loop() {
//  Serial2.println("Hello Boss");
  Serial2.print(a);
  delay(1500);
}
