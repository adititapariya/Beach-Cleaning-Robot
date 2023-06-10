#include <PS4Controller.h>
#include <EasyTransfer.h>

#define EsptoMega Serial2

int X,Y = 0;

EasyTransfer ED;

struct senddata{
  int16_t x;
  int16_t y;  
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
  // Below has all accessible outputs from the controller
  if (PS4.isConnected()) {
    X = PS4.data.analog.stick.lx;
    Y = PS4.data.analog.stick.ly;
    // Serial.print(X);
    // Serial.print(" ");
    // Serial.println(Y);
  }
  psdata.x=map(X,-128,128,0,255);
  psdata.y=map(Y,-128,128,0,255);
  ED.sendData(); 
  delay(20); 





































































































































































  
  Serial.print(psdata.x);
  Serial.print(" ");    
  Serial.println(psdata.y);    
  
  delay(50);
}
