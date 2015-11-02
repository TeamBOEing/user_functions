/*
 * BOEbot.cpp
 * Author: Corbin Murrow, Cody Crossley
 * Date: 28 October 2015
 * Version: 1.5
 *
 * This file contains the library code for BOEbot funcitonality.
 *
 * ======= VERSION HISTORY =======
 * Version 1.5: Updated function names and functionality - CM - 28 October 2015
 * Version 1.4: Fixed some =/== errors in motors, added max speed var - CC - 26 October 2015
 * Version 1.3: Merged versions 1.1 and 1.2 together - CM - 26 October 2015
 * Version 1.2: Added IR, LED, and playSound functions - CC - 21 October 2015
 * Version 1.1: Added motor and LDR functions - CM - 21 October 2015
 * Version 1.0: Created file - CC - 21 October 2015
 */

#include "BOEbot.h"
#include <Servo.h>

Servo leftServo;
Servo rightServo;

// Sets up pin directions and Serial Monitor
void initialize()
{
  Serial.begin(BAUD);

  // Set user feedback/debug LEDs as output
  pinMode(LED_PIN_GREEN, OUTPUT);
  pinMode(LED_PIN_RED, OUTPUT);

  // Set photoresistors as inputs
  pinMode(LDR_LEFT, INPUT);
  pinMode(LDR_RIGHT, INPUT);

  // Set IR receivers as inputs
  pinMode(IR_RIGHT_RX, INPUT);
  pinMode(IR_LEFT_RX, INPUT);
}

// Turns left motor forward a specific speed (int speed)
void turnLeftMotorForward(unsigned int speed)
{
  if (speed > MAX_SPEED)
  {
    Serial.print("Left motor maximum speed exceeded. Max speed: ");
    Serial.print(MAX_SPEED);
    Serial.print(". Provided Speed: ");
    Serial.print(speed);
    Serial.println(". Speed set to max speed.");
    speed = MAX_SPEED;
  }

  if (!leftServo.attached())
    leftServo.attach(MOTOR_LEFT);

  leftServo.write(MOTOR_STOP_VALUE + speed);
}

// Turns left motor backward a specific speed (int speed)
void turnLeftMotorBackward(unsigned int speed)
{
  if (speed > MAX_SPEED)
  {
    Serial.print("Left motor maximum speed exceeded. Max speed: ");
    Serial.print(MAX_SPEED);
    Serial.print(". Provided Speed: ");
    Serial.print(speed);
    Serial.println(". Speed set to max speed.");
    speed = MAX_SPEED;
  }

  if (!leftServo.attached())
    leftServo.attach(MOTOR_LEFT);

  leftServo.write(MOTOR_STOP_VALUE - speed);
}

// Stops the left motor
void stopLeftMotor()
{
  leftServo.detach();
}

// Turns right motor forward a specific speed (int speed)
void turnRightMotorForward(unsigned int speed)
{
  if (speed > MAX_SPEED)
  {
    Serial.print("Right motor maximum speed exceeded. Max speed: ");
    Serial.print(MAX_SPEED);
    Serial.print(". Provided Speed: ");
    Serial.print(speed);
    Serial.println(". Speed set to max speed.");
    speed = MAX_SPEED;
  }

  if (!rightServo.attached())
    rightServo.attach(MOTOR_RIGHT);

  rightServo.write(MOTOR_STOP_VALUE - speed);
}

// Turns right motor backward a specific speed (int speed)
void turnRightMotorBackward(unsigned int speed)
{
  if (speed > MAX_SPEED)
  {
    Serial.print("Right motor maximum speed exceeded. Max speed: ");
    Serial.print(MAX_SPEED);
    Serial.print(". Provided Speed: ");
    Serial.print(speed);
    Serial.println(". Speed set to max speed.");
    speed = MAX_SPEED;
  }

  if (!rightServo.attached())
    rightServo.attach(MOTOR_RIGHT);

  rightServo.write(MOTOR_STOP_VALUE + speed);
}

// Stops the right motor
void stopRightMotor()
{
  rightServo.detach();
}

// Returns value of left IR
bool leftObstacle()
{
  return digitalRead(IR_LEFT_RX);
}

// Returns value of right IR
bool rightObstacle()
{
  return digitalRead(IR_RIGHT_RX);
}

// Wrapper for analogRead of left light value
int getLeftLight()
{
  return analogRead(LDR_LEFT);
}

// Wrapper for analogRead of right light value
int getRightLight()
{
  return analogRead(LDR_RIGHT);
}

// Turns the green LED on
void turnOnGreenLED()
{
  digitalWrite(LED_PIN_GREEN, HIGH);
}

// Turns the green LED off
void turnOffGreenLED()
{
  digitalWrite(LED_PIN_GREEN, LOW);
}

// Turns the red LED on
void turnOnRedLED()
{
  digitalWrite(LED_PIN_RED, HIGH);
}

// Turns the red LED off
void turnOffRedLED()
{
  digitalWrite(LED_PIN_RED, LOW);
}

// Wrapper for tone function
void playSound(int freq, int duration)
{
  tone(SPEAKER_PIN, freq, duration);
}

// Stop the presses!
void halt()
{
  stopLeftMotor();
  stopRightMotor();
  while(1);
}
