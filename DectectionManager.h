
#pragma once
class DectectionManager {
public:
  const int TRIGGER_PIN = A0;
  const int ECHO_PIN = A1;


public:
  void init() {
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
  }

  float getDistance() {
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = (duration / 2) / 29.1;
    Serial.println(distance);
    return distance;
  }

  
};