void motor::setMotorSpeed(int percent) {
  byte speedByte; // used to set the duty-cycle on the speedPin signal
  motor::_speed = percent; // save the percent speed to object
  percent = constrain(percent, -100, 100); // constrain the percent
  if (percent > 0) { // if direction is forward
    speedByte = map(percent, 0, 100, 255, 0); // map the percent to a byte
    analogWrite(_speedPin, speedByte); // set the speed signal
    digitalWrite(motor::_pin2, HIGH); // turn the wheels forward
    digitalWrite(motor::_pin1, LOW);
  }
  else if (percent < 0) { // if direction is backwards
    speedByte = map(percent, 0, 100, 255, 0); // map the percent to a byte
    analogWrite(motor::_speed, speedByte); // set the speed signal
    digitalWrite(motor::_pin2, LOW); // turn the wheels backwards
    digitalWrite(motor::_pin1, HIGH);
  }
  else { // if percent is 0
    motor::stopMotor(); // stopping the motor
  }
}

void motor::stopMotor() { // stops the motor
  digitalWrite(motor::_pin1, LOW); // both pins are low -> wheel does not turn
  digitalWrite(motor::_pin2, LOW);
  analogWrite(motor::_speed, 255); // speedByte is 255 -> 0 speed
  motor::_speed = 0;
}

int motor::getSpeed() { // returns the motorSpeed in percent
  return motor::_speed; // positive is forward and negative is backwards
}
