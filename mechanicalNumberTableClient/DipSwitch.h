

class DipSwitch {
  public:
    DipSwitch(int pin1, int pin2, int pin3, int pin4);
    int getState();
  private:
    int _pin[4];
};