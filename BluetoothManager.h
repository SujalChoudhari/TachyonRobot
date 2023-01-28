#pragma once
#include "Constants.h"
class BluetoothManager {
public:
  const int RATE_OF_COMMUNICATION = 9600;

public:
  void init() {
    Serial.begin(RATE_OF_COMMUNICATION);
  }

  char next() {
    if (Serial.available()) {
      return Serial.read();
    }
    return STATE_NULL;
  }

  void send(char data) {
    Serial.write(data);
  }
};