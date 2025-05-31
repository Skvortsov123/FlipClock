#ifndef WeakStepper_H
#define WeakStepper_H


class WeakStepper {
public:
  WeakStepper();
  WeakStepper(int pin1, int pin2, int pin3, int pin4);
  void setRPM(float rpm); //Best RPM 5-20
  void move_zero(); //Moving  to zero position
  void move_to(float distance);  //Set coordinates in mm
  void zeroCoordinates();
  void setCoordinates(float coordinates);
  bool ready(); //Return true when ready

private:
  void _stepManager(long amountStep);
  void _stepper(int seqIN); 
  float _calcRPM(float rpm);

  int _pin[4];
  float _rpm = 20;
  int _step = 0;
  long _stepTick1 = 0;
  unsigned long _timer1 = 0;
  bool _flagRD = 0;
  float _stepFactor = 290.68; //290.68 = 8 * 11 / 31 * (4096 / 40)
};

#endif
