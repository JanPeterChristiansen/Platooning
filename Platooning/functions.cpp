#include "Arduino.h"
#include "functions.h"

float constrainf(float x, float min, float max) {
  if (x > max) {
    return max;
  }
  else if (x < min) {
    return min;
  }
  else {
    return x;
  }
}

float mapf(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
