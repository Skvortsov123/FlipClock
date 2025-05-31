#include "Manager.h"
Manager man;

void setup() {
  man.setup();
  //Serial.begin(9600);
}

void loop() {
  man.tick();
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
U -> 30
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