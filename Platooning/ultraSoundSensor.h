#ifndef ULTRASOUNDSENSOR_H
#define ULTRASOUNDSENSOR_H

#include "Arduino.h"

class ringBuffer {
  public:
    ringBuffer(int SIZE);
    void addValue(float value);
    float mean();

  private:
    int SIZE;
    int indx = 0;
    float *buffer;
	
};

class ultraSoundSensor { // object that handles the Ultra Sound Sensor
  public:
    ultraSoundSensor(int GND = 34, int echo = 36,
                     int trig = 38, int Vcc = 40);
    float getDistance();

  private:
    int trig;
    int echo;
    int Vcc;
    int GND;

};

#endif
