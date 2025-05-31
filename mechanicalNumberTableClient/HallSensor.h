
class HallSensor {
  public:
    HallSensor(int pin);
    void onTick();
    bool state();
    bool triggered();
    bool unTriggered();
  //private:
    int _pin;
    bool _newState = 1;
    bool _previousState = 1;
};
