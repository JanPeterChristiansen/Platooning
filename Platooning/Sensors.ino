float ultraSoundSensor::getDistance() {
  // Measuring the distance from the US sensor in cm
  unsigned long t; // time difference between trig and echo
  // float s; // distance based on the time difference
  // send a pulse to trigger
  digitalWrite(trig, HIGH);
  delay(0.01); 
  digitalWrite(trig, LOW);
  // measuring the time difference
  t = pulseIn(echo, HIGH); // wait for echo and measure time delay
  // s = t * 0.034 / 2.0;  // distance in cm
  // _distance = s; // save the distance to object
  return t * 0.034 / 2.0; // return the distance in cm
}
