#include "DipSwitch.h"
#include "Arduino.h"

DipSwitch::DipSwitch(int pin1, int pin2, int pin3, int pin4) {
  _pin[0] = pin1;
  _pin[1] = pin2;
  _pin[2] = pin3;
  _pin[3] = pin4;
  for (int i = 0; i < 4; i++) {
    pinMode(_pin[i], INPUT_PULLUP);
  } 
}

int DipSwitch::getState() {
  int decimal = 0;
  for (int i = 0; i < 4; i++) {
    decimal = (decimal << 1) | !digitalRead(_pin[i]);
  }
  return decimal;
}
