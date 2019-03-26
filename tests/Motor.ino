void motor::setMotorSpeed(int percent) {
  byte speedByte;
  motor::_speed = percent;
  percent = constrain(percent, -100, 100);
  if (percent > 0) {
    speedByte = map(percent, 0, 100, 255, 0);
    analogWrite(_speedPin, speedByte);
    digitalWrite(motor::_pin2, HIGH);
    digitalWrite(motor::_pin1, LOW);
  }
  else if (percent < 0) {
    speedByte = map(percent, 0, 100, 255, 0);
    analogWrite(motor::_speed, speedByte);
    digitalWrite(motor::_pin2, LOW);
    digitalWrite(motor::_pin1, HIGH);
  }
  else {
    motor::stopMotor();
  }
}

void motor::stopMotor() {
  digitalWrite(motor::_pin1, LOW);
  digitalWrite(motor::_pin2, LOW);
  analogWrite(motor::_speed, 255);
}
