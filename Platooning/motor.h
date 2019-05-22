#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "wheel.h"
#include "functions.h"

class motor {
  public:
    motor(int rightPin1 = 2, int rightPin2 = 3, int rightSpeedPin = 6,
          int leftPin1 = 4, int leftPin2 = 5, int leftSpeedPin = 7,
          int rightCorrection = 0, int leftCorrection = 0);
    void setSpeed(float speed, int turn = 0);
    float getSpeed();
    float getTurn();
    float getRightSpeed();
    float getLeftSpeed();

  private:
    wheel right;
    wheel left;
    float speed = 0;
    int turn = 0;

};

#endif
