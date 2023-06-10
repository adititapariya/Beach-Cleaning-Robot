#include <EasyTransfer.h>
#define EsptoMega Serial2

#define RXp2 17
#define TXp2 16
String incomingByte;

EasyTransfer ED;

struct receivedata{
  int16_t x;
  int16_t y;
};

receivedata psdata;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  EsptoMega.begin(9600);
  ED.begin(details(psdata),&EsptoMega);
  Serial2.begin(9600);
}
void loop() {
  ED.receiveData();
  Serial.println(psdata.x);
  Serial.println(psdata.y);
  Serial.println(' ');
  delay(50);
}
