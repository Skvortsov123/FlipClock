#include "Arduino.h"
#include "Led.h"

Led::Led(int pin) {
  _pin = pin;
  pinMode(pin, INPUT);
}

void Led::Tick() {
  if (_mode == 0) {
    _lightOff();
  }else if (_mode == 1) {
    _lightOn();
  }else if (_mode == 2) {
    if (millis() - _blinkTime > _timer1) {
      _timer1 = millis();
      _lightSwitchState();
    }
  }
}

void Led::blink(int time) {
  _mode = 2;
  _blinkTime = time/2;
}

void Led::on() {
  _mode = 1;
}

void Led::off() {
  _mode = 0;
}

void Led::_lightSwitchState() {
  if (_stateSW1 == 0) {
    _stateSW1 = 1;
    _lightOn();
  }else{
    _stateSW1 = 0;
    _lightOff();
  }
}

void Led::_lightOn() {
  digitalWrite(_pin, 1);
}

void Led::_lightOff() {
  digitalWrite(_pin, 0);
}
