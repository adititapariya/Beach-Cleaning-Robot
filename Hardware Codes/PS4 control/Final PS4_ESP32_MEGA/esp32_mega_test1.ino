#include <EasyTransfer.h>
#define EsptoMega Serial2

#define RXp2 17
#define TXp2 16
String incomingByte;

EasyTransfer ED;

struct receivedata{
  int16_t lx;
  int16_t ly;
  int16_t rx;
  int16_t ry;
  int16_t up;
  int16_t down;
  int16_t left;
  int16_t right;
  int16_t triangle;
  int16_t square;
  int16_t cross;
  int16_t circle; 
  int16_t l1;
  int16_t r1;
  int16_t l2;
  int16_t r2;
  int16_t share;
  int16_t options;
  int16_t l3;
  int16_t r3;
  int16_t touchpad;
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
  Serial.print(psdata.lx);
  Serial.print(" ");
  Serial.print(psdata.ly);
  Serial.print(" ");
  Serial.print(psdata.rx);
  Serial.print(" ");
  Serial.print(psdata.ry);
  Serial.print(" ");
  Serial.print(psdata.up);
  Serial.print(' ');
  Serial.print(psdata.down);
  Serial.print(' ');
  Serial.print(psdata.left);
  Serial.print(' ');
  Serial.print(psdata.right);
  Serial.print(' ');
  Serial.print(psdata.triangle);   
  Serial.print(" ");
  Serial.print(psdata.square);   
  Serial.print(" ");
  Serial.print(psdata.cross);   
  Serial.print(" ");
  Serial.print(psdata.circle);   
  Serial.print(" ");
  Serial.print(psdata.l1);   
  Serial.print(" ");
  Serial.print(psdata.r1);   
  Serial.print(" ");
  Serial.print(psdata.l2);   
  Serial.print(" ");
  Serial.print(psdata.r2);   
  Serial.print(" ");
  Serial.print(psdata.share);   
  Serial.print(" ");
  Serial.print(psdata.options);   
  Serial.print(" ");
  Serial.print(psdata.l3);   
  Serial.print(" ");
  Serial.print(psdata.r3);   
  Serial.print(" ");
  Serial.print(psdata.touchpad);   
  Serial.println(" ");
  delay(50);
}
