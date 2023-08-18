#include "Arduino.h"
#include "FSRMonitor.h"

FSRMonitor::FSRMonitor(int pin) {
  pinMode(pin, INPUT);
  _pin = pin;
}

int FSRMonitor::readPinValue(){
  int value = analogRead(_pin);
  int mappedValue = map(value, 0, 1023, 0, 5000);
  return mappedValue;
}
