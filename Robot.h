#pragma once
#include "BluetoothManager.h"
#include "Constants.h"
#include "ServoManager.h"
#include "DectectionManager.h"
#include "MotorManager.h"

// Robot class Manages all the Managers and Controls the Logic of the Vehicle.

class Robot {
private:
  BluetoothManager mBluetoothManager;
  ServoManager mServoManager;
  DectectionManager mDetectionManager;
  MotorManager mMotorManager;
  char mCurrentState = STATE_STOP;

public:
  // Initialise all Managers. Must be called in `Setup` function
  void Init() {
    mBluetoothManager.Init();
    mServoManager.Init();
    mDetectionManager.Init();
    mMotorManager.Init(255);
  }

  // Poll and Handle Inputs. Must be called inside `Loop` function.
  void Update() {
    pollInputs();
    handleInputs();
  }

private:
  void pollInputs() {
    char character = mBluetoothManager.Next();
    if (character != STATE_NULL) mCurrentState = character;
  }

  void handleInputs() {
    switch (mCurrentState) {
      case STATE_FRONT:
        handleForward();
        break;
      case STATE_BACK:
        handleBackward();
        break;
      case STATE_LEFT:
        handleLeft();
        break;
      case STATE_RIGHT:
        handleRight();
        break;
      default: // i.e. NULL or STOP
        handleStop();
        break;
    }
  }

  /**
    Check if it is save to move in a specific direction.
    This rotates the Servo and gets the distance. Depending on the SAFE distances in Constants.h,
    It returns true or false.
  */
  bool isSafeToMove(char direction) {
    int angle = 0;
    if (direction == STATE_FRONT) angle = RELATIVE_FRONT_ANGLE;
    else if (direction == STATE_LEFT) angle = RELATIVE_LEFT_ANGLE;
    else if (direction == STATE_RIGHT) angle = RELATIVE_RIGHT_ANGLE;
    mServoManager.RotateTowards(angle);
    
    if(angle != 90) delay(500);

    int distance = mDetectionManager.GetDistance();
    if (direction == STATE_FRONT && distance > SAFE_DISTANCE_FRONT) return true;
    else if (direction == STATE_LEFT && distance > SAFE_DISTANCE_LEFT) return true;
    else if (direction == STATE_RIGHT && distance > SAFE_DISTANCE_RIGHT) return true;
    else if (direction == STATE_BACK) return true;
    else return false;
  }

  void handleForward() {
    if (isSafeToMove(STATE_FRONT)) {
      mMotorManager.MoveForward();
    } else {
      mCurrentState = STATE_STOP;
    }
  }

  void handleBackward() {
    mMotorManager.MoveBackward();
  }

  void handleLeft() {
    if (isSafeToMove(STATE_LEFT)) {
      mMotorManager.MoveLeft();
      delay(500);
      mCurrentState = STATE_FRONT;
    } else {
      mCurrentState = STATE_STOP;
    }
  }
  void handleRight() {
    if (isSafeToMove(STATE_RIGHT)) {
      mMotorManager.MoveRight();
      delay(500);
      mCurrentState = STATE_FRONT;
    } else {
      mCurrentState = STATE_STOP;
    }
  }

  void handleStop() {
    mMotorManager.Stop();
    mServoManager.RotateTowards(RELATIVE_FRONT_ANGLE);
  }
};