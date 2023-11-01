/*
  Created by: Evan St-Pierre
  Created on: Oct 2023
  Utilizes a HC-SR04 and a Servo through an Arduino
*/

#include <Servo.h>

Servo servoNumber1;

const int TRIG_PIN = 3;
const int ECHO_PIN = 2;

float duration, distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  servoNumber1.attach(7);
  servoNumber1.write(0);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.0343) / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  
  if (distance > 50) {
    servoNumber1.write(90);
  } else {
    servoNumber1.write(0);
  }
}
