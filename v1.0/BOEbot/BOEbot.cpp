/*
 * BOEbot.cpp
 * Author: Corbin Murrow, Cody Crossley
 * Date: 26 October 2015
 * Version: 1.3
 *
 * This file contains the library code for BOEbot funcitonality.
 *
 * ======= VERSION HISTORY =======
 * Version 1.3: Merged versions 1.1 and 1.2 together - CM - 26 October 2015
 * Version 1.2: Added IR, LED, and playSound functions - CC - 21 October 2015
 * Version 1.1: Added motor and LDR functions - CM - 21 October 2015
 * Version 1.0: Created file - CC - 21 October 2015
 */

#include "BOEbot.h"
#include <Servo.h>

Servo leftServo;
Servo rightServo;

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

void rightMotor(int speed)
{
  if (speed > 100)
  {
    Serial.println("Right motor speed above allowable forward threshold. Adjusting to max forward speed.");
    speed == 100;
  } else if (speed < -100)
  {
    Serial.println("Right motor speed above allowable backward threshold. Adjusting to max backward speed.");
    speed == -100;
  }

  if (speed == 0)
  {
    if (rightServo.attached())
      rightServo.detach();
  } else
  {
    if (!rightServo.attached())
      rightServo.attach(MOTOR_RIGHT);

    rightServo.writeMicroseconds(MOTOR_STOP_VALUE - speed);
  }
}

void leftMotor(int speed)
{
  if (speed > 100)
  {
    Serial.println("Left motor speed above allowable forward threshold. Adjusting to max forward speed.");
    speed == 100;
  } else if (speed < -100)
  {
    Serial.println("Left motor speed above allowable backward threshold. Adjusting to max backward speed.");
    speed == -100;
  }

  if (speed == 0)
  {
    if (leftServo.attached())
      leftServo.detach();
  } else
  {
    if (!leftServo.attached())
      leftServo.attach(MOTOR_LEFT);

    leftServo.writeMicroseconds(MOTOR_STOP_VALUE + speed);
  }
}

int getLeftLight()
{
  return analogRead(LDR_LEFT);
}

int getRightLight()
{
  return analogRead(LDR_RIGHT);
}

// Turns red LED to passed in on/off
void setRedLED(int state) {
  if (state)
    digitalWrite(LED_PIN_RED, HIGH);
  else
    digitalWrite(LED_PIN_RED, LOW);
}

// Turns green LED to passed in on/off
void setGreenLED(int state) {
  if (state)
    digitalWrite(LED_PIN_GREEN, HIGH);
  else
    digitalWrite(LED_PIN_GREEN, LOW);
}

// Wrapper for tone function
void playSound(int freq, int duration) {
  tone(SPEAKER_PIN, freq, duration);
}

// Returns value of left LDR
int getLeftIR() {
  return digitalRead(LDR_LEFT);
}

// Returns value of right LDR
int getRightIR() {
  return digitalRead(LDR_RIGHT);
}
