#include <Wire.h>

#define  Button1  2
#define  Button2  3

void setup() {
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  Wire.begin(); // Initialize I2C communication
  Serial.begin(9600);
}

void loop() {
  // Read button states
  byte Button1_State = digitalRead(Button1);
  byte Button2_State = digitalRead(Button2);
  Serial.println(Button2_State);
  // Send button states over I2C
  Wire.beginTransmission(8); //Address of the Arduino Slave 
  Wire.write(Button1_State); 
  Wire.write(Button2_State);  
  Wire.endTransmission();

  delay(100);
}
