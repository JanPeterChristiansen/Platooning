#include "Arduino.h"
#include "pidControl.h"

pidControl::pidControl(float ref = 20.0, float Kp = 50, float Ki = 0, float Kd = 0) {
  pidControl::ref = ref;
  pidControl::Kp = Kp;
  pidControl::Ki = Ki;
  pidControl::Kp = Kp;
}

void pidControl::setSpeed(float speed) {
  pidControl:: speed = speed;
}
float pidControl::getSpeed() {
  return speed;
}
void pidControl::cal(float s) {
  float e, de;
  float P, I, D;

  e = s - ref;
  P = Kp * e;

  i += e;
  I = Ki * i;

  de = e - d;
  D = Kd * de;
  d = e;

  u = P + I + D;
  u /= 100;
  speed += u;
}
