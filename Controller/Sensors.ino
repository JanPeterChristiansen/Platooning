float getDistance(struct US* US) {
  // Measuring the distance from the US sensor in cm
  unsigned long t;

  // send a pulse to trigger
  digitalWrite(US -> trig, HIGH);
  delay(0.01);
  digitalWrite(US -> trig, LOW);

  t = pulseIn(US -> echo, HIGH); // wait for echo and measure time delay
  return t * 0.034 / 2.0;  // return the distance in cm
}
