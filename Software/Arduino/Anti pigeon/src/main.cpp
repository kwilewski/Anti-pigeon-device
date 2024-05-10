#include <Arduino.h>
#include <Servo.h>

Servo leftServo, rightServo;
int leftServoPin = 4, rightServoPin = 5;
int pirSensor = 6;
int timeOfMovement = 500;

void fullMovement();


void setup() {
  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);
  pinMode(pirSensor, INPUT);
}

void loop() {
  int value = digitalRead(pirSensor);
  if (value == 1){
    fullMovement();
  }
  delay(100);
}

void fullMovement(){
  leftServo.write(0);
  rightServo.write(180);
  delay(timeOfMovement);
  leftServo.write(90);
  rightServo.write(90);
  delay(1500);
  leftServo.write(180);
  rightServo.write(0);
  delay(timeOfMovement);
  leftServo.write(90);
  rightServo.write(90);
  delay(1000);
}