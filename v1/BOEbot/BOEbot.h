/*
 * BOEbot.h
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
 * Version 1.1: Added motor and LDR prototypes - CM -21 October 2015
 * Version 1.0: Created header - CC - 21 October 2015
 */

#ifndef BOEbot_h
#define BOEbot_h

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
#define BAUD 115200               // Speed which Serial monitor transmits
#define IR_SEND_FREQ 38500        // Hz signal of IR LEDs
#define MOTOR_STOP_VALUE 1500     // The nominal stop value
#define MAX_SPEED 200             // Fastest forward/backward speed allowed

// User function prototypes
void initialize();                // Sets up pin directions and Serial Monitor
void turnLeftMotorForward(int);   // Turns left motor forward a specific speed (int speed)
void turnLeftMotorBackward(int);  // Turns left motor backward a specific speed (int speed)
void stopLeftMotor();             // Stops the left motor
void turnRightMotorForward(int);  // Turns right motor forward a specific speed (int speed)
void turnRightMotorBackward(int); // Turns right motor backward a specific speed (int speed)
void stopRightMotor();            // Stops the right motor
bool leftObstacle();              // True if obstacle detected on left IR
bool rightObstacle();             // True if obstacle detected on right IR
int getLeftLight();               // Wrapper for analogRead of left light value
int getRightLight();              // Wrapper for analogRead of right light value
void turnOnGreenLED();            // Turns the green LED on
void turnOffGreenLED();           // Turns the green LED off
void turnOnRedLED();              // Turns the red LED on
void turnOffRedLED();             // Turns the red LED off
void playSound(int, int);         // Wrapper for tone function (int freq, int duration)


#endif
