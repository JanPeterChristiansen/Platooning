// Headers:
class motor {
  public:
    motor(int pin1, int pin2, int speedPin) {
      motor::_pin1 = pin1;
      pinMode(motor::_pin1, OUTPUT);
      motor::_pin2 = pin2;
      pinMode(motor::_pin2, OUTPUT);
      motor::_speedPin = speedPin;
      pinMode(motor::_speedPin, OUTPUT);
    }
    void setMotorSpeed(int percent);
    void stopMotor();

  private:
    int _pin1;
    int _pin2;
    int _speedPin;
    int _speed;
};

class ultraSoundSensor {
  public:
    ultraSoundSensor(int trig, int echo) {
      ultraSoundSensor::_trig = trig;
      pinMode(ultraSoundSensor::_trig, OUTPUT);
      ultraSoundSensor::_echo = echo;
      pinMode(ultraSoundSensor::_echo, INPUT);
    }
    float getDistance();

  private:
    int _trig;
    int _echo;
    int _distance;
};





void setup() {

  motor rightMotor(3, 4, 9);
  motor leftMotor(5, 6, 9);
  ultraSoundSensor US(38, 36);
  digitalWrite(40,HIGH);
  digitalWrite(34,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
