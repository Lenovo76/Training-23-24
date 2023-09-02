#include <Wire.h>

#define Led 9

void setup() {
  pinMode(Led, OUTPUT);
  Wire.begin(8);              // Address the slave as 8
  Wire.onReceive(Control_led); 
  Serial.begin(9600);           
}

void loop() {
  
}

void Control_led(int numBytes) {
  if (Wire.available()) {
    byte buttonState1 = Wire.read(); // Read button state 1
    byte buttonState2 = Wire.read(); // Read button state 2

    // Control the LED based on button states
    
     if (buttonState1 == LOW && buttonState2 == LOW) {
      analogWrite(Led, 0);
      Serial.println("No message");
    } else if (buttonState1 == HIGH && buttonState2 == LOW) {
      analogWrite(Led, 128); 
      Serial.println("Vector focused");
    } else if (buttonState1 == LOW && buttonState2 == HIGH) {
      analogWrite(Led, 192); 
      Serial.println("Vector distracted");
    } else if (buttonState1 == HIGH && buttonState2 == HIGH) {
      analogWrite(Led, 255);
      Serial.println("Glitch");
    }
  }
}