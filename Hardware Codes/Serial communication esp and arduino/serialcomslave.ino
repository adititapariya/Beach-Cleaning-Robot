#include <EasyTransfer.h>

//create object
EasyTransfer ET; 
struct RECEIVE_DATA_STRUCTURE{
  //put your variable definitions here for the data you want to send
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  int Rx;
  int Ry;
  int Lx;
  int Ly;
};

//give a name to the group of data
RECEIVE_DATA_STRUCTURE PS4data;
void setup() {
  Serial2.begin(9600);
  ET.begin(details(PS4data), &Serial2);
  pinMode(13, OUTPUT);
}

void loop() {
  //check and see if a data packet has come in. 
  if(ET.receiveData()){
    //this is how you access the variables. [name of the group].[variable name]
    //since we have data, we will blink it out.
      Serial2.println("aaya");
      digitalWrite(13, HIGH); 
      Serial2.print("Lx = ");
      Serial2.println(PS4data.Lx);
      Serial2.print("Ly = ");
      Serial2.println(PS4data.Ly);
      Serial2.print("Rx = ");
      Serial2.println(PS4data.Rx);
      Serial2.print("Ry = ");
      Serial2.println(PS4data.Ry);
      digitalWrite(13, LOW);
    }
    delay(250);
}
 
