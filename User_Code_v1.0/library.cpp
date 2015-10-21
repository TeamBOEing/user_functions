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

// User function definitions

// Turns red LED to passed in on/off
void setRedLed(int state) {
  if (state)
    digitalWrite(LED_PIN_RED, HIGH);
  else
    digitalWrite(LED_PIN_RED, LOW);
}

// Turns green LED to passed in on/off
void setGreenLed(int state) {
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
int getLeftIr() {
  return analogRead(LDR_LEFT);
}

// Returns value of right LDR
int getRightIr() {
  return analogRead(LDR_RIGHT);
}
