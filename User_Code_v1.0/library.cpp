/*
 * Library.cpp
 * Author: Cody Crossley
 * Date: 21 October 2015
 * Version: 1.2
 * 
 * Something goes here
 * 
 * ======= VERSION HISTORY =======
 * Version 1.2: Added IR, LED, and playSound functions - CC - 21 October 2015
 * Version 1.0: Created file - CC - 21 October 2015
 */

#include "library.h"

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

void setStopValue(int stop)
{
  if (stopValue < 1475)
    Serial.println("Stop value below acceptable threshold, please try again.");
  else if (stopValue > 1525)
    Serial.println("Stop value above acceptable threshold, please try again.");
  else
    stopValue = stop;
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

    leftServo.writeMicroseconds(stopValue + speed);
  }
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
      rightServo.attach(MOTOR_RIGHT));

    rightServo.writeMicroseconds(stopValue - speed);
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
