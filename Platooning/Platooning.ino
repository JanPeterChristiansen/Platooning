#include "platooning.h"

motor M;
bluetooth BT;
ultraSoundSensor US;
pidControl PID;

const int targetSpeed = 50;

void setup() {
  
  M.setSpeed(targetSpeed);

}

void loop() {

  US.measureDistance();



  PID.setSpeed(M.getSpeed());
  PID.cal(US.getDistance());
  M.setSpeed(PID.getSpeed());



  if (M.getSpeed() > targetSpeed) {
    M.setSpeed(targetSpeed);
  }
  else if (M.getSpeed() > targetSpeed < -targetSpeed) {
    M.setSpeed(-targetSpeed);
  }


}
