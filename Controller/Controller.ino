#include "platooning.h"

motor M;
ultraSoundSensor US;
bluetooth BT;


void setup() {
  Serial.begin(9600);

}

void loop() {
  
  BT.receive();
  BT.handleNewData();

  M.setSpeed(BT.getSpeed(), BT.getTurn());

}
