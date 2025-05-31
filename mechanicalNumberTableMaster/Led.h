

class Led {
  public:
    Led(int pin);
    void tick();
    void blink(int time);
    void on();
    void off();
  private:
    void _lightOn();
    void _lightOff();
    void _lightSwitchState();
    int _pin;
    int _mode = 0;
    bool _stateSW1 = 0;
    int _blinkTime;
    unsigned long _timer1 = 0;
};