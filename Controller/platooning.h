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

class bluetooth { // nobject that handles communication with mobile app via bluetooth
  public:
    bluetooth(int RX, int TX) { // use this constructor if Vcc, GND, state and EN are connected directly
      bluetooth::_RX = RX;
      pinMode(bluetooth::_RX, OUTPUT);
      bluetooth::_TX = TX;
      pinMode(bluetooth::_TX, INPUT);
      bluetooth::beginSerial();
    }
    /*
        bluetooth(int RX, int TX, int GND, int Vcc) { // use this constructor if state and enable are connected directly but Vcc and GND are not
          bluetooth::_RX = RX;
          pinMode(bluetooth::_RX, OUTPUT);
          bluetooth::_TX = TX;
          pinMode(bluetooth::_TX, INPUT);
          bluetooth::_GND = GND;
          pinMode(bluetooth::_GND, OUTPUT);
          digitalWrite(bluetooth::_GND, LOW);
          bluetooth::_Vcc = Vcc;
          pinMode(bluetooth::_Vcc, OUTPUT);
          digitalWrite(bluetooth::_Vcc, HIGH);
          bluetooth::beginSerial();
        }
        bluetooth(int state, int RX, int TX, int GND, int Vcc, int EN) { // use this constructor if every pin has to be set.
          // Caution: RX/TX can only handle 3.3 V.
          bluetooth::_state = state;
          pinMode(bluetooth::_state, OUTPUT);
          // set the default state setting here!!!
          bluetooth::_RX = RX;
          pinMode(bluetooth::_RX, OUTPUT);
          bluetooth::_TX = TX;
          pinMode(bluetooth::_TX, INPUT);
          bluetooth::_GND = GND;
          pinMode(bluetooth::_GND, OUTPUT);
          digitalWrite(bluetooth::_GND, LOW);
          bluetooth::_Vcc = Vcc;
          pinMode(bluetooth::_Vcc, OUTPUT);
          digitalWrite(bluetooth::_Vcc, HIGH);
          bluetooth::_EN = EN;
          pinMode(bluetooth::_EN, OUTPUT);
          // set the default enable setting here!!!
          bluetooth::beginSerial();
        }
    */
    void beginSerial();

  private:
    int _RX;
    int _TX;
    /*
      int _state;
      int _GND;
      int _Vcc;
      int _EN;
    */
};
