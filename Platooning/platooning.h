class wheel { // Object that handles motors
  public:
    wheel(int pin1, int pin2, int speedPin, float correction) {
      // Contructor is called with the H-bridge pins aswell as the speedPin
      wheel::pin1 = pin1;
      pinMode(pin1, OUTPUT);
      wheel::pin2 = pin2;
      pinMode(pin2, OUTPUT);
      wheel::speedPin = speedPin;
      pinMode(speedPin, OUTPUT);
      wheel::correction = correction;
    }
    void setSpeed(int percent); // turns on the motor with the given speed
    void stop(); // stops the motor
    int getSpeed();

  private:
    int pin1;
    int pin2;
    int speedPin;
    int speed;
    int correction;
};

class motor {
  public:
    motor(int rightPin1 = 2, int rightPin2 = 3, int rightSpeedPin = 6,
          int leftPin1 = 4, int leftPin2 = 5, int leftSpeedPin = 7,
          int rightCorrection = 40, int leftCorrection = 0) :
      right(rightPin1, rightPin2, rightSpeedPin, rightCorrection),
      left(leftPin1, leftPin2, leftSpeedPin, leftCorrection) {}
    void setSpeed(int speed, int turn = 0);
    int getSpeed();
    int getTurn();
    int getRightSpeed();
    int getLeftSpeed();

  private:
    wheel right;
    wheel left;
    int speed = 0;
    int turn = 0;
};

class ringBuffer {
  public:
    ringBuffer(int SIZE) {
      ringBuffer::SIZE = SIZE;
      buffer = new float[SIZE];
    }
    void addValue(float value);
    float mean();

  private:
    int SIZE;
    int indx = 0;
    float *buffer;
};


class ultraSoundSensor { // object that handles the Ultra Sound Sensor
  public:
    ultraSoundSensor(int GND = 34, int echo = 36,
                     int trig = 38, int Vcc = 40) {
      // use this constructor if Vcc and GND are digital pins
      ultraSoundSensor::trig = trig;
      pinMode(trig, OUTPUT);
      ultraSoundSensor::echo = echo;
      pinMode(echo, INPUT);
      ultraSoundSensor::Vcc = Vcc;
      pinMode(Vcc, OUTPUT);
      digitalWrite(Vcc, HIGH);
      ultraSoundSensor::GND = GND;
      pinMode(GND, OUTPUT);
      digitalWrite(GND, LOW);
    }
    float getDistance();

  private:
    int trig;
    int echo;
    int Vcc;
    int GND;

};

class bluetooth { // object that handles communication with mobile app via bluetooth
  public:
    bluetooth(int RX = 1, int TX = 0) {
      bluetooth::RX = RX;
      pinMode(RX, OUTPUT);
      bluetooth::TX = TX;
      pinMode(TX, INPUT);
      // beginSerial();
      Serial3.begin(38400);
    }
    void receive();
    void handleNewData();
    int getSpeed();
    int getTurn();
    bool getPlatooning();

  private:
    int RX;
    int TX;
    const static byte numChars = 32;
    char receivedChars[numChars];
    bool newData = false;
    int intFromPC = 0;
    int speed = 0;
    int turn = 0;
    bool reverse = false;
    bool platooning = false;

    void decideReceivedData();
    void parseData();
    void beginSerial();
};

class pidControl {
  public:
    pidControl(float ref = 20.0, float Kp = 50, float Ki = 0, float Kd = 0) {
      pidControl::ref = ref;
      pidControl::Kp = Kp;
      pidControl::Ki = Ki;
      pidControl::Kp = Kp;

    }
    void setSpeed(int speed);
    void cal(float s);
    int getSpeed();


  private:
    float ref;
    int speed;
    float Kp;
    float Ki;
    float Kd;
    float u, i, d;

};
