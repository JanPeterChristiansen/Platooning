void wheel::setSpeed(int percent) {
  byte speedByte; // used to set the duty-cycle on the speedPin signal
  percent = constrain(percent, -100, 100); // constrain the percent
  speed = percent; // save the percent speed to object
  if (percent > 0) { // if direction is forward
    speedByte = map(percent, 0, 100, 255, 0); // map the percent to a byte
    analogWrite(speedPin, speedByte); // set the speed signal
    digitalWrite(pin2, HIGH); // turn the wheels forward
    digitalWrite(pin1, LOW);
  }
  else if (percent < 0) { // if direction is backwards
    speedByte = map(-percent, 0, 100, 255, 0); // map the percent to a byte
    analogWrite(speedPin, speedByte); // set the speed signal
    digitalWrite(pin2, LOW); // turn the wheels backwards
    digitalWrite(pin1, HIGH);
  }
  else { // if percent is 0
    stop(); // stopping the motor
  }
}

void wheel::stop() { // stops the motor
  digitalWrite(pin1, LOW); // both pins are low -> wheel does not turn
  digitalWrite(pin2, LOW);
  analogWrite(speedPin, 255); // speedByte is 255 -> 0 speed
  speed = 0;
}

int wheel::getSpeed() { // returns the motorSpeed in percent
  return speed; // positive is forward and negative is backwards
}

void motor::setSpeed(int speed, int turn = 0) {
  speed = constrain(speed, -100, 100);
  turn = constrain(turn, -100, 100);
  motor::speed = speed;
  motor::turn = turn;

  if (turn > 0) {
    right.setSpeed(speed * (1.0 - turn / 100.0));
    left.setSpeed(speed);
  }
  else if (turn < 0) {
    right.setSpeed(speed);
    left.setSpeed(speed * (1.0 + turn / 100.0));
  }
  else {
    right.setSpeed(speed);
    left.setSpeed(speed);
  }
}

int motor::getRightSpeed() {
  return right.getSpeed();
}

int motor::getLeftSpeed() {
  return left.getSpeed();
}

int motor::getSpeed() {
  return speed;
}

int motor::getTurn() {
  return turn;
}
