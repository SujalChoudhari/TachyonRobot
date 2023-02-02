// Using AdaFruit Motor Library and Servo
#include <AFMotor.h>
#include <Servo.h>

// Using the Robot Class created locally 
#include "Robot.h"

Robot robot;

void setup() {
  robot.Init();
}

void loop() {
  robot.Update();
}
