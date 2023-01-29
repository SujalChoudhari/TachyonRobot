#include <AFMotor.h>
#include <Servo.h>

#include "Robot.h"

Robot robot;

void setup() {
  robot.Init();
}

void loop() {
  robot.Update();
}
