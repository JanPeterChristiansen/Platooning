class motor { // Object that handles motors
  public:
    motor(int pin1, int pin2, int speedPin) { // Contructor is called with the H-bridge pins aswell as the speedPin
      motor::_pin1 = pin1;
      pinMode(motor::_pin1, OUTPUT);
      motor::_pin2 = pin2;
      pinMode(motor::_pin2, OUTPUT);
      motor::_speedPin = speedPin;
      pinMode(motor::_speedPin, OUTPUT);
    }
    void setMotorSpeed(int percent); // turns on the motor with the given speed
    void stopMotor(); // stops the motor
    int getSpeed();

  private:
    int _pin1;
    int _pin2;
    int _speedPin;
    int _speed;
};

class ultraSoundSensor { // object that handles the Ultra Sound Sensor
  public:
    ultraSoundSensor(int echo, int trig) { // use this constructor if Vcc and GND connected directly to 5V and GND
      ultraSoundSensor::_trig = trig;
      pinMode(ultraSoundSensor::_trig, OUTPUT);
      ultraSoundSensor::_echo = echo;
      pinMode(ultraSoundSensor::_echo, INPUT);
    }
    ultraSoundSensor(int GND, int echo, int trig, int Vcc) { // use this constructor if Vcc and GND are digital pins
      ultraSoundSensor::_trig = trig;
      pinMode(ultraSoundSensor::_trig, OUTPUT);
      ultraSoundSensor::_echo = echo;
      pinMode(ultraSoundSensor::_echo, INPUT);
      ultraSoundSensor::_Vcc = Vcc;
      pinMode(ultraSoundSensor::_Vcc, OUTPUT);
      digitalWrite(ultraSoundSensor::_Vcc, HIGH);
      ultraSoundSensor::_GND = GND;
      pinMode(ultraSoundSensor::_GND, OUTPUT);
      digitalWrite(ultraSoundSensor::_GND, LOW);
    }
    float getDistance();

  private:
    int _trig;
    int _echo;
    int _Vcc;
    int _GND;
    int _distance;
};

class bluetooth { // object that handles communication with mobile app via bluetooth
  public:
    bluetooth(int RX = 14, int TX = 15) { // use this constructor if Vcc, GND, state and EN are connected directly
      bluetooth::_RX = RX;
      pinMode(bluetooth::_RX, OUTPUT);
      bluetooth::_TX = TX;
      pinMode(bluetooth::_TX, INPUT);
      // bluetooth::_beginSerial();
      Serial3.begin(38400);
    }
    void receive();
    void handleNewData();
    void getMotorSpeed();

  private:
    int _RX;
    int _TX;
    const static byte _numChars = 32;
    char _receivedChars[_numChars];
    bool _newData = false;
    int _intFromPC = 0;
    int _motorSpeed = 0;

    void _decideReceivedData();
    void _parseData();
    void _beginSerial();
};
