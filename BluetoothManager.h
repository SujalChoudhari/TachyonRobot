
class BluetoothManager {
  InputHandler() {
    Serial.begin(9600);
  }

  char next() {
    if (Serial.available()) {
      return Serial.read();
    }
  }

  void send(char data) {
    Serial.write(data);
  }
};