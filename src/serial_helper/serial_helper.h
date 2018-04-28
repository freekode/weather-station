#include <Arduino.h>

class SerialHelper {
  Stream &serial;
  String inputString = "";
  boolean inputComplete = false;

  public:
    SerialHelper(Stream &serial):
      serial(serial) {
        inputString.reserve(10);
      };
    String sendAtCommand(const char *command);
    String receive();
    size_t print(const __FlashStringHelper *);
    size_t print(const String &);
    size_t println(const __FlashStringHelper *);
    size_t println(const String &);
};
