/*
 * BOEbot.h
 * Author: Corbin Murrow, Cody Crossley
 * Date: 21 October 2015
 * Version: 1.3
 *
 * Something goes here
 *
 * ======= VERSION HISTORY =======
 * Version 1.3: Merged versions 1.1 and 1.2 together - CM - 26 October 2015
 * Version 1.2: Added IR, LED, and playSound functions - CC - 21 October 2015
 * Version 1.1: Added motor and LDR prototypes - CM -21 October 2015
 * Version 1.0: Created header - CC - 21 October 2015
 */

#ifndef library_h
#define library_h

// Need a full path
// http://stackoverflow.com/questions/6504211/is-it-possible-to-include-a-library-from-another-library-using-the-arduino-ide
#include "Arduino.h"

// Pins
#define MOTOR_LEFT 5              // Left motor control pin
#define MOTOR_RIGHT 6             // Right motor control pin
#define LED_PIN_GREEN 7           // Correlated with feedback of left side of board
#define LED_PIN_RED 8             // Correlated with feedback of right side of board
#define SPEAKER_PIN 9             // Pin speaker is attached to
#define IR_TX 10                  // PWM 38.5kHz signal to two IR LEDs
#define IR_LEFT_RX 18             // IR receiver on left side of BOEbot
#define IR_RIGHT_RX 16            // IR receiver on right side of BOEbot
#define LDR_LEFT A4               // Photoresistor on left side of board
#define LDR_RIGHT A2              // Photoresistor on right side of board

// Constants
#define BAUD 115200          // Speed which Serial monitor transmits
#define IR_SEND_FREQ 38500        // Hz signal of IR LEDs
#define MOTOR_STOP_VALUE 1500     // The nominal stop value

// User function prototypes
void initialize();
void setRedLED(int);              // Turns red LED to passed in on/off (int state)
void setGreenLED(int);            // Turns green LED to passed in on/off (int state)
void playSound(int, int);         // Wrapper for tone function (int freq, int duration)
int getLeftIR();                  // Returns value of left LDR
int getRightIR();                 // Returns value of right LDR
void rightMotor(int speed);
void leftMotor(int speed);
int getLeftLight();
int getRightLight();

#endif
