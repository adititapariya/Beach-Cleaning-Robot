#include <PS4Controller.h>
#include <EasyTransfer.h>

//create object
EasyTransfer ET;

struct SEND_DATA_STRUCTURE{
  //put your variable definitions here for the data you want to send
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  int Rx;
  int Ry;
  int Lx;
  int Ly;
};

//give a name to the group of data
SEND_DATA_STRUCTURE PS4data;

void setup() {
  Serial.begin(9600);
  PS4.begin("ac:12:03:3c:28:72");
  Serial.println("Ready.");
  //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc.
  Serial2.begin(9600);
  ET.begin(details(PS4data), &Serial2);
  pinMode(13, OUTPUT);
}

void loop() {
  if (PS4.isConnected()) {
    if (PS4.LStickX()) {
      PS4data.Lx = PS4.LStickX();
    }
    if (PS4.LStickY()) {
      PS4data.Ly = PS4.LStickY();
    }
    if (PS4.RStickX()) {
      PS4data.Rx = PS4.RStickX();
    }
    if (PS4.RStickY()) {
      PS4data.Ry = PS4.RStickY();
    }
  }
  ET.sendData();

  delay(500);
}
