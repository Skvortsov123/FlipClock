

class ButtonModule {
  public:
    ButtonModule(int pin1, int pin2);
    bool getButtonA();
    bool getButtonB();
  private:
    int pin1;
    int pin2;
    unsigned long timer1 = 0;
    unsigned long timer2 = 0;
};