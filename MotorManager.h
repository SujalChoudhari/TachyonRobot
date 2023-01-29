#pragma once
#include <AFMotor.h>
class MotorManager {
private:
  AF_DCMotor mFrontLeft;
  AF_DCMotor mFrontRight;
  AF_DCMotor mRearLeft;
  AF_DCMotor mRearRight;
  int mSpeed;

public:
  MotorManager() : mFrontLeft(1), mFrontRight(2), mRearLeft(3), mRearRight(4) {
    mSpeed = 255;
  }
  void init(int motorSpeed) {
    mSpeed = motorSpeed;
    mFrontLeft.setSpeed(mSpeed);
    mFrontRight.setSpeed(mSpeed);
    mRearLeft.setSpeed(mSpeed);
    mRearRight.setSpeed(mSpeed);
  }
  void moveForward() {
    mFrontLeft.run(FORWARD);
    mFrontRight.run(FORWARD);
    mRearLeft.run(FORWARD);
    mRearRight.run(FORWARD);
  }
  void moveBackward() {
    mFrontLeft.run(BACKWARD);
    mFrontRight.run(BACKWARD);
    mRearLeft.run(BACKWARD);
    mRearRight.run(BACKWARD);
  }
  void moveLeft() {
    mFrontLeft.run(BACKWARD);
    mFrontRight.run(FORWARD);
    mRearLeft.run(BACKWARD);
    mRearRight.run(FORWARD);
  }
  void moveRight() {
    mFrontLeft.run(FORWARD);
    mFrontRight.run(BACKWARD);
    mRearLeft.run(FORWARD);
    mRearRight.run(BACKWARD);
  }
  void stop() {
    mFrontLeft.run(RELEASE);
    mFrontRight.run(RELEASE);
    mRearLeft.run(RELEASE);
    mRearRight.run(RELEASE);
  }
};
