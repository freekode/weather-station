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
        btInputString.reserve(200);
        softwareInputString.reserve(200);
      };
    void sendAtCommand(const char *command);
    String receiveFromBt();
    String receiveFromSoftware();
};
