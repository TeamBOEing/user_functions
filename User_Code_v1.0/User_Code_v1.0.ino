/*
 * User Code Library v1.0
 * Author: Corbin Murrow, Cody Crossley
 * Date: 21 October 2015
 * Version: 1.2
 * 
 * 
 * 
 * ======= VERSION HISTORY =======
 * Version 1.2: Added IR, LED, and playSound functions - CC - 21 October 2015
 * Version 1.0: Created Project - CM - 21 October 2015
 */

// We might want to add setMotor{Left/Right}Stop
#include <Servo.h>
#include "library.h"

void setup() {
  Serial.begin(BAUD_RATE);
  
  // Set user feedback/debug LEDs as output
  pinMode(LED_PIN_GREEN, OUTPUT);
  pinMode(LED_PIN_RED, OUTPUT);

  // Set photoresistors as inputs
  pinMode(LDR_LEFT, INPUT);
  pinMode(LDR_RIGHT, INPUT);

  // Set IR receivers as inputs
  pinMode(IR_PIN_RIGHT_RECEIVE, INPUT);
  pinMode(IR_PIN_LEFT_RECEIVE, INPUT);
}

void loop() {

}
