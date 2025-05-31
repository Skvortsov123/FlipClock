//#include "HardwareSerial.h"
#include "Arduino.h"
#include "WeakStepper.h"


WeakStepper::WeakStepper() {
    _pin[0] = 8;
    _pin[1] = 9;
    _pin[2] = 10;
    _pin[3] = 11;
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}



WeakStepper::WeakStepper(int pin1, int pin2, int pin3, int pin4) {
    _pin[0] = pin1;
    _pin[1] = pin2;
    _pin[2] = pin3;
    _pin[3] = pin4;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
}



void WeakStepper::setRPM(float rpm) {
  _rpm = rpm;
}



float WeakStepper::_calcRPM(float rpm) {  //1 RPM = micro delay 14648
  return 14648 / rpm;                     //Return delay between steps in microSeconds
}



void WeakStepper::move_to(float distance) {  //MAKE LONG
  _stepManager(distance * _stepFactor);  //(8 ErrorFactor) gears 31/11, one rotatione = 4096 steps, 40 number of cards, (4096 / 40) to prevent overfloading
}



void WeakStepper::_stepManager(long stepPosition) {
  _flagRD = false;  //Not ready for next command

  if (micros() < _timer1) {
    _timer1 = 0;
  }

  if (_stepTick1 != stepPosition && micros() - (_calcRPM(_rpm) + _timer1) >= 0) {
    _stepTick1++;
    _timer1 = micros();
    _step++;
    if (_step >= 8) _step = 0;  //if more that 7 = state 0
    if (_stepTick1 > _stepFactor * 40) _stepTick1 = 0;  //if index 40 then index 0
    _stepper(_step);
    if (_stepTick1 == stepPosition) {
      _flagRD = true;
      _stepper(-1); //Default to reduce power consuption
    }
  }
}



void WeakStepper::zeroCoordinates() {
  _stepTick1 = 0;
}



void WeakStepper::setCoordinates(float coordinates) {
  _stepTick1 = coordinates * _stepFactor;
}



bool WeakStepper::ready(){
  return _flagRD;
}



void WeakStepper::_stepper(int seqIN) {  //Total 4096 miniSteps
  bool _coil[4];

  switch (seqIN) {
    case 0:
      {
        _coil[0] = 1;
        _coil[1] = 0;
        _coil[2] = 0;
        _coil[3] = 0;
        break;
      }
    case 1:
      {
        _coil[0] = 1;
        _coil[1] = 1;
        _coil[2] = 0;
        _coil[3] = 0;
        break;
      }
    case 2:
      {
        _coil[0] = 0;
        _coil[1] = 1;
        _coil[2] = 0;
        _coil[3] = 0;
        break;
      }
    case 3:
      {
        _coil[0] = 0;
        _coil[1] = 1;
        _coil[2] = 1;
        _coil[3] = 0;
        break;
      }
    case 4:
      {
        _coil[0] = 0;
        _coil[1] = 0;
        _coil[2] = 1;
        _coil[3] = 0;
        break;
      }
    case 5:
      {
        _coil[0] = 0;
        _coil[1] = 0;
        _coil[2] = 1;
        _coil[3] = 1;
        break;
      }
    case 6:
      {
        _coil[0] = 0;
        _coil[1] = 0;
        _coil[2] = 0;
        _coil[3] = 1;
        break;
      }
    case 7:
      {
        _coil[0] = 1;
        _coil[1] = 0;
        _coil[2] = 0;
        _coil[3] = 1;
        break;
      }
    default:
      {
        _coil[0] = 0;
        _coil[1] = 0;
        _coil[2] = 0;
        _coil[3] = 0;
        break;
      }
  }

  for (int p = 0; p < 4; p++) {
    digitalWrite(_pin[p], _coil[p]);
  }
}
