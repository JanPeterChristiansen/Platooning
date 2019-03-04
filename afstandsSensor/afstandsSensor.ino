/*  Define the trigger and echo pin
    SetUp the pinModes
    call getDistance() to get the distance in cm
*/

const int enable = 11;
const int trig = 12;
const int echo = 13;


void setup() {

  Serial.begin(115200);
  pinMode(enable, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(enable, HIGH);

}

void loop() {
  Serial.println(getDistance(), 3);
}

float getDistance() {
  // Measuring the distance from the US sensor in cm
  unsigned long t;

  // send a pulse to trigger
  digitalWrite(trig, HIGH);
  delay(0.01);
  digitalWrite(trig, LOW);


  t = pulseIn(echo, HIGH);  // wait for echo and measure time delay
  return t * 0.034 / 2.0;  // return the distance in cm

}
