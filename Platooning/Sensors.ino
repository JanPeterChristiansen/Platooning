/* ultraSoundSensor */

float ultraSoundSensor::getDistance() {
  // adds a distance measurement to the buffer, in cm
  unsigned long t; // time difference between trig and echo
  float s;
  static ringBuffer distance(10);
  // float s; // distance based on the time difference
  // send a pulse to trigger
  digitalWrite(trig, HIGH);
  delay(0.01);
  digitalWrite(trig, LOW);
  // measuring the time difference
  t = pulseIn(echo, HIGH, 3000); // wait for echo and measure time delay
  s = t * 0.034 / 2.0;
  if (s == 0) {
    s = 99;
  }
  distance.addValue(s); // add measurement to buffer
  return distance.mean();
}


/* ringBuffer */

void ringBuffer::addValue(float value) { // adds value to buffer
  buffer[indx++] = value; // add value
  if (indx > SIZE - 1) { // cycle index
    indx = 0;
  }
}

float ringBuffer::mean() { // calculate buffer mean
  float sum = 0; // sum of buffer
  for (int i = 0; i < SIZE; i++) { // sum buffer values
    sum += buffer[i];
  }
  return sum / SIZE; // return mean
}
