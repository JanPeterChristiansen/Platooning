#include "motor.h"
#include "ultraSoundSensor.h"
#include "bluetooth.h"
#include "pidControl.h"

motor M;
bluetooth BT;
ultraSoundSensor US;
pidControl PID;


const int targetSpeed = 50;
const int deadZone = 35;
const int minStartSpeed = 100;
const int delayTime = 150;
bool startNeeded = false;


void setup() {}

void loop() {

      // Measure and receive information
      float s = US.getDistance();
      BT.receive();
      BT.handleNewData();


      if (BT.getPlatooning()) { // platooning is set to ON

        // run PID control loop
        PID.setSpeed(M.getSpeed());
        PID.cal(US.getDistance());

        // check for too low motor speed
        if (PID.getSpeed() < deadZone && PID.getSpeed() > -deadZone ) {
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
        }

        // constrain motor speed
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
      else { // platooning is set to OFF
        M.setSpeed(BT.getSpeed(), BT.getTurn());
      }

}
