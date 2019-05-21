#include "platooning.h"

motor M;
bluetooth BT;
ultraSoundSensor US;
pidControl PID;

const int targetSpeed = 50;

const int deadZone = 35;      //// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
const int minStartSpeed = 85; //!!!!!!!!!
bool startNeeded = false;     //// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int delayTime = 150;          //// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void setup() {
  Serial.begin(9600);
}

void loop() {

  float s = US.getDistance();

  PID.setSpeed(M.getSpeed());
  PID.cal(s);



  if (PID.getSpeed() < deadZone && PID.getSpeed() > -deadZone ) {       //// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    startNeeded = true;
  }

  if (PID.getSpeed() > deadZone && startNeeded == true) {
    M.setSpeed(minStartSpeed);
    delay(delayTime);
    M.setSpeed(PID.getSpeed());
    startNeeded = false;
  }
  else if (PID.getSpeed() < -deadZone && startNeeded == true) {
    M.setSpeed(-minStartSpeed);
    delay(delayTime);
    M.setSpeed(PID.getSpeed());
    startNeeded = false;
  }                                     //// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  if (PID.getSpeed() > targetSpeed) {
    M.setSpeed(targetSpeed);
  }
  else if (PID.getSpeed() < -targetSpeed) {
    M.setSpeed(-targetSpeed);
  }
  else {
    M.setSpeed(PID.getSpeed());
  }


 // Serial.print(millis());
 // Serial.print(",");
  Serial.print(M.getSpeed());
  Serial.print(",");
  Serial.println(s);
 // Serial.print(",");
 // Serial.println(startNeeded);



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
