#ifndef FSRMonitor_h
#define FSRMonitor_h
#include "Arduino.h"

class FSRMonitor {
  public:
    FSRMonitor(int pin);
    int readPinValue();
  private:
    int _pin;
};
#endif
