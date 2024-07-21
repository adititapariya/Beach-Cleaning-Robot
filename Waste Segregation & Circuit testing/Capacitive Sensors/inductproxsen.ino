// Capacitive Proximity Sensor LJC18A3-B-Z/AX Test for Different Materials
//Black - data, blue - ground, Red - VCC

const int sensorPin = A0; // Connect the sensor output to Arduino digital pin 2
int sensorThreshold = 0; // Variable to store the sensor threshold for different materials
int sensorValue = 0;     // Variable to store the sensor reading

void calibrateSensor();
void setup() {
  Serial.begin(9600);    // Initialize serial communication at 9600 baud
  calibrateSensor();     // Call the calibration function during setup
}

void loop() {
  // Read the sensor value
  sensorValue = analogRead(sensorPin);
  Serial.print("Value = ");
  Serial.println(sensorValue);

  // Compare the sensor value with the calibrated threshold
  /*if (sensorValue == HIGH) {
    Serial.println("No object detected.");
  } 
  else if(sensorValue == 1022 || sensorValue == 1023) {
    Serial.println("Other Material");
  }
  else {
    Serial.print("Plastic Detected : ");
    Serial.println(sensorValue);
  }*/
  delay(500); // You can adjust the delay to change the sensor reading rate
}


void calibrateSensor() {
  Serial.println("Calibrating the sensor. Please remove all objects from the sensor area.");
  delay(5000); // Allow time to clear the sensor area for calibration
  
  int sum = 0;
  const int numReadings = 50; // Number of readings to average for calibration
  
  for (int i = 0; i < numReadings; i++) {
    sum += analogRead(sensorPin);
    delay(50); // Add a small delay between readings
  }
  
  int baseline = sum / numReadings;
  
  Serial.print("Calibration complete. Baseline value: ");
  Serial.println(baseline);
  
  sensorThreshold = baseline -30; // Adjust the threshold as needed based on the material being detected
  // You may need to adjust the threshold value based on your specific setup and materials.
}
