struct motor { // Pin setup for motor
  int speed;
  int pin1;
  int pin2;
};

struct motor right = {9, 3, 4};
struct motor left = {9, 5, 6};

struct US { // pin setup for US sensor
  const int Vcc = 40;
  const int trig = 38;
  const int echo = 36;
  const int GND = 34;
};
struct US US;

// dummies:

int targetSpeed = 50;
int motorSpeed = targetSpeed;
float targetDistance = 20.0;


void setup() {

  pinMode(right.pin1, OUTPUT);
  pinMode(right.pin2, OUTPUT);
  pinMode(left.pin1, OUTPUT);
  pinMode(left.pin2, OUTPUT);
  stopMotor(&left);
  stopMotor(&right);

  pinMode(US.Vcc, OUTPUT);
  pinMode(US.trig, OUTPUT);
  pinMode(US.echo, INPUT);
  pinMode(US.GND, OUTPUT);
  digitalWrite(US.Vcc, HIGH);
  digitalWrite(US.GND, LOW);

  Serial.begin(9600);
  Serial.print("Setup Done");

  setMotorSpeed(&left, targetSpeed);
  setMotorSpeed(&right, targetSpeed);

}

void loop() {

  if (getDistance(&US) < 10.0 ) {
    motorSpeed = 0;
  }
  else {
    motorSpeed = targetSpeed;
  }
  
  Serial.println(getDistance(&US), 3);
  Serial.println(motorSpeed);
  setMotorSpeed(&left, motorSpeed);
  setMotorSpeed(&right, motorSpeed);

}
