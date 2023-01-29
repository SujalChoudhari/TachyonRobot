#pragma once
#include "Constants.h"

// Class Responsible for communication between controller and vehicle.
class BluetoothManager {
public:
  // Constant variable to set the communication baud rate
  const int COMMUNICATION_RATE = 9600;

public:
  /**
   * Initializes the Serial communication with a baud rate of 9600.
   * Must be called inside the Setup function
   */
  void Init() {
    Serial.begin(COMMUNICATION_RATE);
  }

  /**
   * Returns the next character on the Serial port if available
   * @return the next character or STATE_NULL if no data available
   */
  char Next() {
    if (Serial.available()) {
      return Serial.read();
    }
    return STATE_NULL;
  }

  /**
   * Sends a single character data to the Serial port
   * @param data the character to be sent
   */
  void Send(char data) {
    Serial.write(data);
  }
};
