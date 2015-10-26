/*
 * Library.h
 * Author: Cody Crossley
 * Date: 21 October 2015
 * Version: 1.2
 * 
 * Something goes here
 * 
 * ======= VERSION HISTORY =======
 * Version 1.2: Added IR, LED, and playSound functions - CC - 21 October 2015
 * Version 1.1: 
 * Version 1.0: Created header - CC - 21 October 2015
 */

#ifndef library_h
#define library_h

// Need a full path
// http://stackoverflow.com/questions/6504211/is-it-possible-to-include-a-library-from-another-library-using-the-arduino-ide
//#include <Servo.h>
#include "Arduino.h"

// Pins
#define MOTOR_LEFT 5              // Left motor control pin
#define MOTOR_RIGHT 6             // Right motor control pin
#define LED_PIN_GREEN 7           // Correlated with feedback of left side of board
#define LED_PIN_RED 8             // Correlated with feedback of right side of board
#define SPEAKER_PIN 9             // Pin speaker is attached to
#define IR_PIN_SEND 10            // PWM 38.5kHz signal to two IR LEDs
#define IR_PIN_LEFT_RECEIVE 18    // IR receiver on left side of BOEbot
#define IR_PIN_RIGHT_RECEIVE 16   // IR receiver on right side of BOEbot
#define LDR_LEFT A4               // Photoresistor on left side of board
#define LDR_RIGHT A2              // Photoresistor on right side of board

// Constants
#define BAUD_RATE 115200          // Speed which Serial monitor transmits
#define IR_SEND_FREQ 38500        // Hz signal of IR LEDs
#define MOTOR_STOP_VALUE 1500     // The nominal stop value

// User function prototypes
void setRedLed(int);              // Turns red LED to passed in on/off (int state)
void setGreenLed(int);            // Turns green LED to passed in on/off (int state)
void playSound(int, int);         // Wrapper for tone function (int freq, int duration)
int getLeftIr();                  // Returns value of left LDR
int getRightIr();                 // Returns value of right LDR

#endif

