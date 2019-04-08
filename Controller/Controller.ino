#include "platooning.h"

// wheel right(2, 3, 4);
// wheel left(5, 6, 7);
ultraSoundSensor US(34, 36, 38, 40);
bluetooth BT(14, 15);
motor M(2, 3, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);

  M.setSpeed(25, -10);

  Serial.println(M.getLeftSpeed());




}

void loop() {



}
