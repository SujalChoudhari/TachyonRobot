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
  char mCurrentState = STATE_FRONT;

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
      default: // i.e. NILL or STOP
        handleStop();
        break;
    }
  }

  bool isSafeToMove(char direction) {
    int angle = 0;
    if (direction == STATE_FRONT) angle = 90;
    else if (direction == STATE_LEFT) angle = 180;
    else if (direction == STATE_RIGHT) angle = 0;
    mServoManager.RotateTowards(angle);
    delay(angle * 2);

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
      delay(1500);
      mCurrentState = STATE_FRONT;
    } else {
      mCurrentState = STATE_STOP;
    }
  }
  void handleRight() {
    if (isSafeToMove(STATE_RIGHT)) {
      // Serial.println("RIG");
      mMotorManager.MoveRight();
      delay(1500);
      // mMotorManager.moveFWD();
      mCurrentState = STATE_FRONT;
    } else {
      mCurrentState = STATE_STOP;
    }
  }

  void handleStop() {
    mMotorManager.Stop();
  }
};