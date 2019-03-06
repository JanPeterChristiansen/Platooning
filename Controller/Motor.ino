void setMotorSpeed(struct motor* motor, int percent) {
  byte speedByte;
  percent = constrain(percent, -100, 100);
  if (percent > 0) {
    speedByte = map(percent, 0, 100, 255, 0);
    analogWrite(motor -> speed, speedByte);
    digitalWrite(motor -> pin2, HIGH);
    digitalWrite(motor -> pin1, LOW);
  }
  else if (percent < 0) {
    speedByte = map(percent, 0, 100, 255, 0);
    analogWrite(motor -> speed, speedByte);
    digitalWrite(motor -> pin2, LOW);
    digitalWrite(motor -> pin1, HIGH);
  }
  else {
    stopMotor(motor);
  }
}

void stopMotor(struct motor* motor) {
  digitalWrite(motor -> pin1, LOW);
  digitalWrite(motor -> pin2, LOW);
  analogWrite(motor -> speed, 255);
}
