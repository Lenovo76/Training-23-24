#include "Timer.h"
Timer my_timer;

//define ultrasonic sensor pins
const int sensor180_trig=A0;
const int sensor180_echo=A1;
const int sensor270_trig=A2;
const int sensor270_echo=A3; 

float measure_distance(int sensorTrig,int sensorEcho){
  //clears the trig pin
  digitalWrite(sensorTrig,LOW);
  delayMicroseconds(2);
  //sends the ultrasonic wave for 10 microseconds
  digitalWrite(sensorTrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorTrig,LOW);
  float duration=pulseIn(sensorEcho,HIGH);
  float distance=(duration/2)*0.0343;
  return distance;
  
}


void setup()
{
  Serial.begin(9600);
  pinMode(sensor180_trig,OUTPUT);
  pinMode(sensor180_echo,INPUT);
  pinMode(sensor270_trig,OUTPUT);
  pinMode(sensor270_echo,INPUT);
  my_timer.every(5,measure_distance); //wait till the next wave to avoid interruption
  
}
void loop()
{
  my_timer.update();
  float x=measure_distance(sensor180_trig,sensor180_echo);
  float y=measure_distance(sensor270_trig,sensor270_echo);
  // print the coordinates on serial monitor
  Serial.print("Coordinates: (");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.println(")");
}
