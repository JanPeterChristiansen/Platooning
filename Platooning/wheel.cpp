#include "Arduino.h"
#include "wheel.h"

wheel::wheel(int pin1, int pin2, int speedPin, int correction) {
  // Contructor is called with the H-bridge pins aswell as the speedPin
  wheel::pin1 = pin1;
  pinMode(pin1, OUTPUT);
  wheel::pin2 = pin2;
  pinMode(pin2, OUTPUT);
  wheel::speedPin = speedPin;
  pinMode(speedPin, OUTPUT);
  wheel::correction = correction;
}

void wheel::setSpeed(float percent) {
  byte speedByte; // used to set the duty-cycle on the speedPin signal
  percent = constrainf(percent, -100, 100); // constrain the percent
  percent = percent * (1.0 - correction / 100.0); // corrects motorspeed so wheels match
  speed = percent; // save the percent speed to object
  if (percent > 0) { // if direction is forward
    speedByte = mapf(percent, 0, 100, 255, 0); // map the percent to a byte
    analogWrite(speedPin, speedByte); // set the speed signal
    digitalWrite(pin2, HIGH); // turn the wheels forward
    digitalWrite(pin1, LOW);
    if (startUp) {
      digitalWrite(speedPin, HIGH);
      delay(10);
    }
    analogWrite(speedPin, speedByte); // set the speed signal
  }
  else if (percent < 0) { // if direction is backwards
    speedByte = mapf(-percent, 0, 100, 255, 0); // map the percent to a byte
    analogWrite(speedPin, speedByte); // set the speed signal
    digitalWrite(pin2, LOW); // turn the wheels backwards
    digitalWrite(pin1, HIGH);
    if (startUp) {
      digitalWrite(speedPin, HIGH);
      delay(10);
    }
    analogWrite(speedPin, speedByte); // set the speed signal
  } 
  else { // if percent is 0
    stop(); // stopping the motor
  }

  if (speed < 25) {
    startUp = true;
  }
  else {
    startUp = false;
  }
}

void wheel::stop() { // stops the motor
  digitalWrite(pin1, LOW); // both pins are low -> wheel does not turn
  digitalWrite(pin2, LOW);
  analogWrite(speedPin, 255); // speedByte is 255 -> 0 speed
  speed = 0;
}

float wheel::getSpeed() { // returns the motorSpeed in percent
  return speed; // positive is forward and negative is backwards
}
