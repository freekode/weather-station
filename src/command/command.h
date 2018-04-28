#include <Arduino.h>

class Command {
  public:
    String runCommand(String);
  private:
    int PARAMS_LENGTH = 30;
    
    String commandLast();
    String commandHistory();
    String commandTest();
    String commandFreeRam();
    String commandSetTime(char*[]);
    void parseCommand(String, char*[]);
};
