float ultraSoundSensor::getDistance() {
  // Measuring the distance from the US sensor in cm
  unsigned long t; // time difference between trig and echo
  // send a pulse to trigger
  digitalWrite(trig, HIGH);
  delay(0.01);
  digitalWrite(trig, LOW);
  // measuring the time difference
  t = pulseIn(echo, HIGH); // wait for echo and measure time delay
  return t * 0.034 / 2.0; // return the distance in cm
}
