#ifndef WHEEL_H
#define WHEEL_H

#include "Arduino.h"
#include "functions.h"

class wheel { // Object that handles motors
  public:
    wheel(int pin1, int pin2, int speedPin, int correction);
    void setSpeed(float percent); // turns on the motor with the given speed
    void stop(); // stops the motor
    float getSpeed();

  private:
    int pin1;
    int pin2;
    int speedPin;
    float speed;
    int correction;

};

#endif
