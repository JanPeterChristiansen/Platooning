#include "platooning.h"

motor M;
// bluetooth BT;
ultraSoundSensor US;
pidControl PID;

const int targetSpeed = 75;

void setup() {

}

void loop() {

  PID.setSpeed(M.getSpeed());
  PID.cal(US.getDistance());

  if (PID.getSpeed() > targetSpeed) {
    M.setSpeed(targetSpeed);
  }
  else if (PID.getSpeed() < -targetSpeed) {
    M.setSpeed(-targetSpeed);
  }
  else {
    M.setSpeed(PID.getSpeed());
  }
}
