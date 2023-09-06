// Defining encoder pins
#define pinA 2
#define pinB 3

volatile long long counter = 0; // Volatile keyword for the counter variable since it is within an interrupt

void setup() {
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinA), ISR_Encoder_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pinB), ISR_Encoder_B, CHANGE);
  Serial.begin(9600); // Moved Serial.begin() to the setup() function
}

void loop() {
  // Print the counter value
  Serial.println(long(counter)); //Explicitly casting counter to long
  
  /**** long long data type may not be directly supported by the println() function, depending on your Arduino board and version. 
  By casting it to long, you can ensure compatibility and print the value correctly. ****/

  delay(100); // Added a delay to avoid flooding the serial output
}

// Interrupt Service Routine for Encoder Pin A
void ISR_Encoder_A() {
  if (digitalRead(pinA) != digitalRead(pinB))
    counter++;
  else
    counter--;
}

// Interrupt Service Routine for Encoder Pin B
void ISR_Encoder_B() {
  if (digitalRead(pinA) == digitalRead(pinB))
    counter++;
  else
    counter--;
}