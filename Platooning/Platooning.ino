#include "platooning.h"

motor M;
bluetooth BT;
ultraSoundSensor US;


void setup() {

}

void loop() {

  BT.receive();
  BT.handleNewData();

  M.setSpeed(BT.getSpeed(), BT.getTurn());

}
