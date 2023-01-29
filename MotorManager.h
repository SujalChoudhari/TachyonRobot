#pragma once
#include <AFMotor.h>
/**
  MotorManager class is used for managing the motors of the robot.
  It uses the Adafruit Motor Shield library for controlling the motors.
*/
class MotorManager {
private:
  AF_DCMotor mFrontLeft;
  AF_DCMotor mFrontRight;
  AF_DCMotor mRearLeft;
  AF_DCMotor mRearRight;
  int mSpeed;

public:
  // Initialise the Motors (AF_DCMotors)
  MotorManager()
    : mFrontLeft(1), mFrontRight(2), mRearLeft(3), mRearRight(4) {
    mSpeed = 255;
  }

  /**
    Set the speeds of the motors to given speed
    Must be called inside the Setup function
    @param motorSpeed Set the Speed of the motors. Ranges from 0 to 255, 0 being stop.
  */
  void Init(int motorSpeed) {
    mSpeed = motorSpeed;
    mFrontLeft.setSpeed(mSpeed);
    mFrontRight.setSpeed(mSpeed);
    mRearLeft.setSpeed(mSpeed);
    mRearRight.setSpeed(mSpeed);
  }
  /**
    Move the Robot
  */
  void MoveForward() {
    mFrontLeft.run(FORWARD);
    mFrontRight.run(FORWARD);
    mRearLeft.run(FORWARD);
    mRearRight.run(FORWARD);
  }

  /**
    Move the Robot
  */
  void MoveBackward() {
    mFrontLeft.run(BACKWARD);
    mFrontRight.run(BACKWARD);
    mRearLeft.run(BACKWARD);
    mRearRight.run(BACKWARD);
  }

  /**
    Move the Robot
  */
  void MoveLeft() {
    mFrontLeft.run(BACKWARD);
    mFrontRight.run(FORWARD);
    mRearLeft.run(BACKWARD);
    mRearRight.run(FORWARD);
  }

  /**
    Move the Robot
  */
  void MoveRight() {
    mFrontLeft.run(FORWARD);
    mFrontRight.run(BACKWARD);
    mRearLeft.run(FORWARD);
    mRearRight.run(BACKWARD);
  }

  /**
    Stop the Robot
  */
  void Stop() {
    mFrontLeft.run(RELEASE);
    mFrontRight.run(RELEASE);
    mRearLeft.run(RELEASE);
    mRearRight.run(RELEASE);
  }
};
