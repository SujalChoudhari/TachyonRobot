#pragma once
#include "Constants.h"

/**
  Manages the Servo by keeping track of the current angle.
*/
class ServoManager {
public:
  const int ATTACHED_PIN = SERVO_PIN_NUMBER;

private:
  Servo mServo;
  int mCurrentDirection = 0;

public:
  // Initialise the servo. Must be called inside the Setup function
  void Init() {
    mServo.attach(ATTACHED_PIN);
  }


  /**
    Turns the servo to make it point at a direction
    @param desiredDirection - The desired deriction to make the servo rotate at, 
    irrespective of the current rotation.
  */
  void RotateTowards(int desiredDirection) {
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