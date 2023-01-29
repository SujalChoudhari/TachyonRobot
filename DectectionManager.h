#pragma once

/**
* Class for managing distance detection using HC-SR04 ultrasonic sensor
*/
class DectectionManager {
public:
  /**
  * Pinout for the trigger pin of the HC-SR04 sensor
  */
  const int TRIGGER_PIN = A0;
  /**
  * Pinout for the echo pin of the HC-SR04 sensor
  */
  const int ECHO_PIN = A1;


public:
  /**
  * Initializes the trigger and echo pins for distance detection.
  * Must be called inside the Setup function
  */
  void Init() {
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
  }

  /**
  * Returns the distance measured by the sensor in cm
  * @return the distance in cm
  */
  float GetDistance() {
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = (duration / 2) / 34.3;
    Serial.println(distance);
    return distance;
  }
};
