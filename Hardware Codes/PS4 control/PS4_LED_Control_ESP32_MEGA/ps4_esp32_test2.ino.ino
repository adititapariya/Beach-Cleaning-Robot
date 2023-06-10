#include <PS4Controller.h>
#include <EasyTransfer.h>

#define EsptoMega Serial2
#define LED_PIN 4

EasyTransfer ED;

struct senddata{
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

senddata psdata;
int16_t ledState = false;

void setup() {
  Serial.begin(9600);
  EsptoMega.begin(9600,SERIAL_8N1,16,17);
  ED.begin(details(psdata),&EsptoMega);
  PS4.begin("4c:d5:77:df:cf:64");
  Serial.println("Ready.");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (PS4.isConnected()){
    psdata.lx = PS4.data.analog.stick.lx;
    psdata.ly = PS4.data.analog.stick.ly;
    psdata.rx = PS4.data.analog.stick.rx;
    psdata.ry = PS4.data.analog.stick.ry;
    psdata.up = PS4.data.button.up;
    psdata.down = PS4.data.button.down;
    psdata.left = PS4.data.button.left;
    psdata.right = PS4.data.button.right;
    psdata.triangle = PS4.data.button.triangle;
    psdata.square = PS4.data.button.square;
    psdata.cross = PS4.data.button.cross;
    psdata.circle = PS4.data.button.circle;
    psdata.l1 = PS4.data.button.l1;
    psdata.r1 = PS4.data.button.r1;
    psdata.l2 = PS4.data.button.l2;
    psdata.r2 = PS4.data.button.r2;
    psdata.share = PS4.data.button.share;
    psdata.options = PS4.data.button.options;
    psdata.l3 = PS4.data.button.l3;
    psdata.r3 = PS4.data.button.r3;
    psdata.touchpad = PS4.data.button.touchpad;

    if (psdata.triangle == 1){
      ledState = true;
    }else if (psdata.up == 1){
      ledState = false;
    }
    if (psdata.square == 1){
      ledState = true;
    }else if (psdata.left == 1){
      ledState = false;
    }
    if (psdata.cross == 1){
      ledState = true;
    }else if (psdata.down == 1){
      ledState = false;
    }
    if (psdata.circle == 1){
      ledState = true;
    }else if (psdata.right == 1){
      ledState = false;
    }
    if (psdata.r1 == 1){
      ledState = true;
    }else if (psdata.l1 == 1){
      ledState = false;
    }
    digitalWrite(LED_PIN, ledState);
  }

  ED.sendData(); 
  delay(20); 
  Serial.print(psdata.lx);
  Serial.print(" ");
  Serial.print(psdata.ly);
  Serial.print(" ");
  Serial.print(psdata.rx);
  Serial.print(" ");
  Serial.print(psdata.ry);
  Serial.print(" ");
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
