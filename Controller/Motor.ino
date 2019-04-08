void wheel::setSpeed(int percent) {
  byte speedByte; // used to set the duty-cycle on the speedPin signal
  _speed = percent; // save the percent speed to object
  percent = constrain(percent, -100, 100); // constrain the percent
  if (percent > 0) { // if direction is forward
    speedByte = map(percent, 0, 100, 255, 0); // map the percent to a byte
    analogWrite(_speedPin, speedByte); // set the speed signal
    digitalWrite(_pin2, HIGH); // turn the wheels forward
    digitalWrite(_pin1, LOW);
  }
  else if (percent < 0) { // if direction is backwards
    speedByte = map(percent, 0, 100, 255, 0); // map the percent to a byte
    analogWrite(_speedPin, speedByte); // set the speed signal
    digitalWrite(_pin2, LOW); // turn the wheels backwards
    digitalWrite(_pin1, HIGH);
  }
  else { // if percent is 0
    stop(); // stopping the motor
  }
}

void wheel::stop() { // stops the motor
  digitalWrite(_pin1, LOW); // both pins are low -> wheel does not turn
  digitalWrite(_pin2, LOW);
  analogWrite(_speedPin, 255); // speedByte is 255 -> 0 speed
  _speed = 0;
}

int wheel::getSpeed() { // returns the motorSpeed in percent
  return _speed; // positive is forward and negative is backwards
}

void motor::setSpeed(int speed, int turn = 0) {
  speed = constrain(speed, -100, 100);
  turn = constrain(turn, -100, 100);
  _speed = speed;
  _turn = turn;

  if (_turn > 0) {
    _right.setSpeed(_speed * (1.0 - turn / 100.0));
    _left.setSpeed(_speed);
  }
  else if (_turn < 0) {
    _right.setSpeed(_speed);
    _left.setSpeed(_speed * (1.0 + turn / 100.0));
  }
  else {
    _right.setSpeed(_speed);
    _left.setSpeed(_speed);
  }
}

int motor::getRightSpeed() {
  return _right.getSpeed();
}

int motor::getLeftSpeed() {
  return _left.getSpeed();
}

int motor::getSpeed() {
  return _speed;
}

int motor::getTurn() {
  return _turn;
}
