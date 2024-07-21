#include <PS4Controller.h>
#include <EasyTransfer.h>

#define EsptoMega Serial2

EasyTransfer ED;

struct senddata{
  int16_t up;
  int16_t down;
  int16_t left;
  int16_t right;
  int16_t triangle;
  int16_t square;
  int16_t cross;
  int16_t circle;
};

senddata psdata;

void setup() {
  Serial.begin(9600);
  EsptoMega.begin(9600,SERIAL_8N1,16,17);
  ED.begin(details(psdata),&EsptoMega);
  PS4.begin("4c:d5:77:df:cf:64");
  Serial.println("Ready.");
}

void loop() {
  if (PS4.isConnected()){
    psdata.up = PS4.data.button.up;
    psdata.down = PS4.data.button.down;
    psdata.left = PS4.data.button.left;
    psdata.right = PS4.data.button.right;
    psdata.triangle = PS4.data.button.triangle;
    psdata.square = PS4.data.button.square;
    psdata.cross = PS4.data.button.cross;
    psdata.circle = PS4.data.button.circle;
  }

  ED.sendData(); 
  delay(20); 
  Serial.print(psdata.up);
  Serial.print(" ");    
  Serial.print(psdata.down); 
  Serial.print(" ");
  Serial.print(psdata.left);
  Serial.print(" ");
  Serial.print(psdata.right);   
  Serial.print(" ");
  Serial.print(psdata.triangle);   
  Serial.print(" ");
  Serial.print(psdata.square);   
  Serial.print(" ");
  Serial.print(psdata.cross);   
  Serial.print(" ");
  Serial.print(psdata.circle);   
  Serial.print(" ");
  delay(50);
}
