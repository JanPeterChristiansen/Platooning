const int speedPin = 9;
const int motorPinL1 = 3;
const int motorPinL2 = 4;
const int motorPinR1 = 5;
const int motorPinR2 = 6;

struct US {
  const int trig = 12;
  const int echo = 13;
};
struct US US;

int motorSpeed = 50;
int afstand = 20;

void setup() {

  pinMode(motorPinL1, OUTPUT);
  pinMode(motorPinL2, OUTPUT);
  pinMode(motorPinR1, OUTPUT);
  pinMode(motorPinR2, OUTPUT);
  
  pinMode(US.trig, OUTPUT);
  pinMode(US.echo, INPUT);
  digitalWrite(11, HIGH);

  Serial.begin(9600);
  Serial.print("Setup Done");
}

void loop() {

  motorSpeed += control(getDistance(&US));
  if (motorSpeed > 50) {
    motorSpeed = 50;
  }
  if (motorSpeed <= 0) {
    motorSpeed = 0;
  }
  Serial.println(motorSpeed);
  delay(1000);

}
