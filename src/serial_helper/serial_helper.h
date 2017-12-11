#include <Arduino.h>

class SerialHelper {
  Stream &softwareSerial;
  Stream &btSerial;
  String btInputString = "";
  boolean btInputComplete = false;
  String softwareInputString = "";
  boolean softwareInputComplete = false;
  public:
    SerialHelper(Stream &softwareSerial, Stream &btSerial):
      softwareSerial(softwareSerial),
      btSerial(btSerial) {
        btInputString.reserve(10);
        softwareInputString.reserve(10);
      };
    void sendAtCommand(const char *command);
    String receiveFromBt();
    String receiveFromSoftware();
};
