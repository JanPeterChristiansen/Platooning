#include "platooning.h"

motor M;
bluetooth BT;
ultraSoundSensor US;
pidControl PID;

const int targetSpeed = 50;

void setup() {
  Serial.begin(9600);
}

void loop() {

  delay(25);

  float s = US.getDistance();

  PID.setSpeed(M.getSpeed());
  PID.cal(s);

  if (PID.getSpeed() > targetSpeed) {
    M.setSpeed(targetSpeed);
  }
  else if (PID.getSpeed() < -targetSpeed) {
    M.setSpeed(-targetSpeed);
  }
  else {
    M.setSpeed(PID.getSpeed());
  }


  Serial.print(millis());
  Serial.print(",");
  Serial.print(M.getSpeed());
  Serial.print(",");
  Serial.println(s);


  /*
    BT.receive();
    BT.handleNewData();


    if (BT.getPlatooning()) {

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
    else {

    M.setSpeed(BT.getSpeed(), BT.getTurn());
    }
  */
}
