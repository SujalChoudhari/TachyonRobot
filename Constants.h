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
