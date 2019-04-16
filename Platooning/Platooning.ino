#include "platooning.h"

motor M;
bluetooth BT;
pidControl PID;
ultraSoundSensor DIST;
void setup() {
  Serial.begin(9600);
  M.setSpeed(50,0);

}

void loop() {

  PID.setSpeed(M.getSpeed());
  PID.cal(DIST.getDistance());
  M.setSpeed(PID.getSpeed());

  Serial.print(DIST.getDistance());
  Serial.print("   ");
  Serial.println(M.getSpeed());
  

}
