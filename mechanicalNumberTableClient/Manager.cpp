#include <Arduino.h>
#include "Manager.h"


Manager::Manager() : stepper(2, 3, 4, 5), hall(9), led(13) {
  stepper.setRPM(14);
}

void Manager::tick() {
  hall.onTick();
  led.Tick();
  if (!_zeroingFlag) {   //Zeroing
    led.blink(250);
    _zeroingFlag = findPosition();
  }else if (!_readyFlag) {            //Normal
    led.blink(2000);
    stepper.move_to(_symbolToShow);
    _readyFlag = stepper.ready();
    if (hall.triggered()) { //Hall sensor adjust position
      stepper.setCoordinates(_hallPosition);
      Serial.println("Position Adjusted!");
    }
  }
}

bool Manager::findPosition() {
  if (hall.triggered()) {
    stepper.setCoordinates(_hallPosition);
    Serial.println("Position Found!");
    return 1;
  }
  stepper.move_to(1000000);
  return 0;
}



void Manager::setPosition(float newPosition) {
  _symbolToShow = newPosition;
  _readyFlag = 0;
}

bool Manager::ifReady() {
  return _readyFlag;
}

/*
1 -> 0
2 -> 1
3 -> 2
4 -> 3
5 -> 4
6 -> 5
7 -> 6
8 -> 7
9 -> 8
0 -> 9
A -> 10
B -> 11
C -> 12
D -> 13
E -> 14
F -> 15
G -> 16
H -> 17
I -> 18
J -> 19
K -> 20
L -> 21
M -> 22
N -> 23
O -> 24
P -> 25
Q -> 26
R -> 27
S -> 28
T -> 29
U -> 30 +
V -> 31
W -> 32
X -> 33
Y -> 34
Z -> 35
+ -> 36
- -> 37
! -> 38
? -> 39
*/