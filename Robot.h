#pragma once
#include "BluetoothManager.h"
#include "Constants.h"
#include "ServoManager.h"
#include "DectectionManager.h"
#include "MotorManager.h"


class Robot {
private:
  BluetoothManager mBluetoothManager;
  ServoManager mServoManager;
  DectectionManager mDetectionManager;
  MotorManager mMotorManager;

  char currentState = STATE_FRONT;

public:
  init() {
    mBluetoothManager.init();
    mServoManager.init();
    mDetectionManager.init();
    mMotorManager.init(255);

    pinMode(13, OUTPUT);
  }

  void loop() {
    pollInputs();
    handleInputs();
  }

  void pollInputs() {
    char character = mBluetoothManager.next();
    if (character != STATE_NULL) currentState = character;
  }

  void handleInputs() {
    switch (currentState) {
      case STATE_FRONT:
        mHandleForward();
        break;
      case STATE_BACK:
        mHandleBackward();
        break;
      case STATE_LEFT:
        mHandleLeft();
        break;
      case STATE_RIGHT:
        mHandleRight();
        break;
      default:
        mHandleStop();
        break;
    }
  }

private:
  bool isSafeToMove(char direction) {
    int angle = 0;
    if (direction == STATE_FRONT) angle = 90;
    else if (direction == STATE_LEFT) angle = 180;
    else if (direction == STATE_RIGHT) angle = 0;
    mServoManager.pointToDirection(angle);
    // delay(20);

    int distance = mDetectionManager.getDistance();
    if (direction == STATE_FRONT && distance > SAFE_DISTANCE_FRONT) return true;
    else if (direction == STATE_BACK) return true;
    else if (direction == STATE_LEFT && distance > SAFE_DISTANCE_LEFT) return true;
    else if (direction == STATE_RIGHT && distance > SAFE_DISTANCE_RIGHT) return true;
    else return false;
  }

  void mHandleForward() {
    if (isSafeToMove(STATE_FRONT)) {
      mMotorManager.moveForward();
      // Serial.println("FWD");
    } else {
      currentState = STATE_STOP;
    }
  }

  void mHandleBackward() {
    mMotorManager.moveBackward();
  }

  void mHandleLeft() {
    if (isSafeToMove(STATE_LEFT)) {
      mMotorManager.moveLeft();
      // Serial.println("LFT");
      delay(1500);
      // mMotorManager.moveFWD();
      currentState = STATE_FRONT;
    } else {
      currentState = STATE_STOP;
    }
  }
  void mHandleRight() {
    if (isSafeToMove(STATE_RIGHT)) {
      // Serial.println("RIG");
      mMotorManager.moveRight();
      delay(1500);
      // mMotorManager.moveFWD();
      currentState = STATE_FRONT;
    } else {
      currentState = STATE_STOP;
    }
  }

  void mHandleStop() {
    mMotorManager.stop();
  }
};