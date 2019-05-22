#ifndef PIDCONTROL_H
#define PIDCONTROL_H

#include "Arduino.h"

class pidControl {
  public:
    pidControl(float ref = 20.0, float Kp = 50, float Ki = 0, float Kd = 0);
    void setSpeed(float speed);
    void cal(float s);
    float getSpeed();

  private:
    float ref;
    float speed;
    float Kp;
    float Ki;
    float Kd;
    float u, i, d;

};

#endif
