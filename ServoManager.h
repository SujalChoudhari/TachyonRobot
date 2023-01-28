#pragma once
#include "Constants.h"

class ServoManager {
public:
  const int ATTACHED_PIN = 10;

private:
  Servo mServo;
  int mCurrentDirection = 0;

public:
  void init() {
    mServo.attach(ATTACHED_PIN);
  }

public:
  void pointToDirection(int desiredDirection) {
    int directionDifference = desiredDirection - mCurrentDirection;
    if (directionDifference > 180) {
      directionDifference -= 360;
    } else if (directionDifference < -180) {
      directionDifference += 360;
    }
    mServo.write(mCurrentDirection + directionDifference);
    mCurrentDirection += directionDifference;
  }
};