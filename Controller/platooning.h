class wheel { // Object that handles motors
  public:
    wheel(int pin1, int pin2, int speedPin) { 
      // Contructor is called with the H-bridge pins aswell as the speedPin
      _pin1 = pin1;
      pinMode(_pin1, OUTPUT);
      _pin2 = pin2;
      pinMode(_pin2, OUTPUT);
      _speedPin = speedPin;
      pinMode(_speedPin, OUTPUT);
    }
    void setSpeed(int percent); // turns on the motor with the given speed
    void stop(); // stops the motor
    int getSpeed();

  private:
    int _pin1;
    int _pin2;
    int _speedPin;
    int _speed;
};

class motor {
  public:
    motor(int rightPin1 = 2, int rightPin2 = 3, int rightSpeedPin = 4,
          int leftPin1 = 5, int leftPin2 = 6, int leftSpeedPin = 7) :
      _right(rightPin1, rightPin2, rightSpeedPin),
      _left(leftPin1, leftPin2, leftSpeedPin) {}
    void setSpeed(int speed, int turn = 0);
    int getSpeed();
    int getTurn();
    int getRightSpeed();
    int getLeftSpeed();

  private:
    wheel _right;
    wheel _left;
    int _speed = 0;
    int _turn = 0;
};

class ultraSoundSensor { // object that handles the Ultra Sound Sensor
  public:
    ultraSoundSensor(int echo, int trig) {
      // use this constructor if Vcc and GND connected directly to 5V and GND
      _trig = trig;
      pinMode(_trig, OUTPUT);
      _echo = echo;
      pinMode(_echo, INPUT);
    }
    ultraSoundSensor(int GND = 34, int echo = 36,
                     int trig = 38, int Vcc = 40) {
      // use this constructor if Vcc and GND are digital pins
      _trig = trig;
      pinMode(_trig, OUTPUT);
      _echo = echo;
      pinMode(_echo, INPUT);
      _Vcc = Vcc;
      pinMode(_Vcc, OUTPUT);
      digitalWrite(_Vcc, HIGH);
      _GND = GND;
      pinMode(_GND, OUTPUT);
      digitalWrite(_GND, LOW);
    }
    float getDistance();

  private:
    int _trig;
    int _echo;
    int _Vcc;
    int _GND;
    // int _distance;
};

class bluetooth { // object that handles communication with mobile app via bluetooth
  public:
    bluetooth(int RX = 14, int TX = 15) { 
      _RX = RX;
      pinMode(_RX, OUTPUT);
      _TX = TX;
      pinMode(_TX, INPUT);
      // _beginSerial();
      Serial3.begin(38400);
    }
    void receive();
    void handleNewData();
    int getSpeed();
    int getTurn();

  private:
    int _RX;
    int _TX;
    const static byte _numChars = 32;
    char _receivedChars[_numChars];
    bool _newData = false;
    int _intFromPC = 0;
    int _speed = 0;
    int _turn = 0;
    bool _reverse = false;

    void _decideReceivedData();
    void _parseData();
    void _beginSerial();
};
