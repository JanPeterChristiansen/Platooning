void pidControl::setSpeed(int speed) {
  pidControl:: speed = speed;
}
int pidControl::getSpeed() {
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

  speed += u;
}

