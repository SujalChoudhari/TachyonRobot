#pragma once
/**
* Safe distance for the front, right and left side of the robot
*/
#define SAFE_DISTANCE_FRONT 10
#define SAFE_DISTANCE_RIGHT 15
#define SAFE_DISTANCE_LEFT 15

/**
* Motor pinout for the robot
*/
#define MOTOR_FRONT_LEFT 1
#define MOTOR_FRONT_RIGHT 4
#define MOTOR_REAR_LEFT 2
#define MOTOR_REAR_RIGHT 3

/**
* State constants for controlling the robot's movement
*/
#define STATE_LEFT 'a'
#define STATE_RIGHT 'd'
#define STATE_FRONT 'w'
#define STATE_BACK 's'
#define STATE_STOP 'o'
#define STATE_NULL '-'

/**
  Relative angles for directions
*/
#define RELATIVE_FRONT_ANGLE 90
#define RELATIVE_LEFT_ANGLE 180
#define RELATIVE_RIGHT_ANGLE 0

#define SPEED_OF_SOUND 29.3
#define COMMUNICATION_BAUD_RATE 9600
#define TRIGGER_PIN_NUMBER A0
#define ECHO_PIN_NUMBER A1
#define SERVO_PIN_NUMBER 10
