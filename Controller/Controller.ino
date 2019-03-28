// Headers:
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
    ultraSoundSensor(int trig, int echo) { // use this constructor if Vcc and GND connected directly to 5V and GND
      ultraSoundSensor::_trig = trig;
      pinMode(ultraSoundSensor::_trig, OUTPUT);
      ultraSoundSensor::_echo = echo;
      pinMode(ultraSoundSensor::_echo, INPUT);
    }
    ultraSoundSensor(int trig, int echo, int Vcc, int GND) { // use this constructor if Vcc and GND are digital pins
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

motor leftMotor(5, 6, 7);
motor rightMotor(2, 3, 4);
ultraSoundSensor US(38, 36, 40, 34);

void setup() {

  leftMotor.setMotorSpeed(100);
  rightMotor.setMotorSpeed(100);
  delay(1000);
  leftMotor.stopMotor();
  rightMotor.stopMotor();
}

void loop() {



}
