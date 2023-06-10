#include <PS4Controller.h>

// the number of the LED pin
const int ledPin = 15;  // 15 corresponds to GPIO15

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
  Serial.begin(115200);
  PS4.begin("ac:12:03:3c:28:72");
  Serial.println("Ready.");

   // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);
}

void loop(){
  // Below has all accessible outputs from the controller
  if (PS4.isConnected()) {
    if (PS4.Right()) Serial.println("Right Button");
    if (PS4.Down()) Serial.println("Down Button");
    if (PS4.Up()) Serial.println("Up Button");
    if (PS4.Left()) Serial.println("Left Button");

    if (PS4.Square()) Serial.println("Square Button");
    if (PS4.Cross()) Serial.println("Cross Button");
    if (PS4.Circle()) Serial.println("Circle Button");
    if (PS4.Triangle()) Serial.println("Triangle Button");

    if (PS4.UpRight()) Serial.println("Up Right");
    if (PS4.DownRight()) Serial.println("Down Right");
    if (PS4.UpLeft()) Serial.println("Up Left");
    if (PS4.DownLeft()) Serial.println("Down Left");

    if (PS4.L1()) Serial.println("L1 Button");
    if (PS4.R1()) Serial.println("R1 Button");

    if (PS4.Share()) Serial.println("Share Button");
    if (PS4.Options()) Serial.println("Options Button");
    if (PS4.L3()) Serial.println("L3 Button");
    if (PS4.R3()) Serial.println("R3 Button");

    if (PS4.PSButton()) Serial.println("PS Button");
    if (PS4.Touchpad()) Serial.println("Touch Pad Button");

    if (PS4.L2()) {
      Serial.printf("L2 button at %d\n", PS4.L2Value());
    }
    if (PS4.R2()) {
      Serial.printf("R2 button at %d\n", PS4.R2Value());
    }

    if (PS4.LStickX()) {
      int value_at_x = PS4.LStickX();
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      //for(value_at_x = 0; value_at_x <= 255; value_at_x++){     // changing the LED brightness with PWM
       // ledcWrite(ledChannel, value_at_x);
       // delay(5);
       // }
       ledcWrite(ledChannel, value_at_x);
    }
   // if (PS4.LStickY()) {
      //Serial.printf("Left Stick y at %d\n", PS4.LStickY());
    //}
    //if (PS4.RStickX()) {
    //  Serial.printf("Right Stick x at %d\n", PS4.RStickX());
    //}
    if (PS4.RStickY()) {
      int value_at_y = PS4.RStickY();
      Serial.printf("Right Stick y at %d\n", PS4.RStickY());
      ledcWrite(ledChannel, value_at_y);
    }

    if (PS4.Charging()) Serial.println("The controller is charging");
    if (PS4.Audio()) Serial.println("The controller has headphones attached");
    if (PS4.Mic()) Serial.println("The controller has a mic attached");

    Serial.printf("Battery Level : %d\n", PS4.Battery());

    Serial.println();
    // This delay is to make the output more human readable
    // Remove it when you're not trying to see the output
    delay(1000);
  }
}
