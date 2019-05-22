#include "Arduino.h"
#include "motor.h"

motor::motor(int leftCorrection = 0, int rightCorrection = 0,
             int rightPin1 = 2, int rightPin2 = 3, int rightSpeedPin = 6,
             int leftPin1 = 4, int leftPin2 = 5, int leftSpeedPin = 7) :
  right(rightPin1, rightPin2, rightSpeedPin, rightCorrection),
  left(leftPin1, leftPin2, leftSpeedPin, leftCorrection) {}


void motor::setSpeed(float speed, int turn = 0) {
  speed = constrainf(speed, -100, 100);
  turn = constrainf(turn, -100, 100);
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

float motor::getRightSpeed() {
  return right.getSpeed();
}

float motor::getLeftSpeed() {
  return left.getSpeed();
}

float motor::getSpeed() {
  return speed;
}

float motor::getTurn() {
  return turn;
}
