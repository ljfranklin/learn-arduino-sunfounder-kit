const int motorPin0 = 10;
const int motorPin1 = 11;
const int motorSpeed = 200;
const int delayTime = 2000;

void setup() {
  pinMode(motorPin0, OUTPUT);
  pinMode(motorPin1, OUTPUT);
}

void loop() {
  spinClockwise();
  delay(delayTime);
  spinCounterclockwise();
  delay(delayTime);
}

void spinClockwise() {
  analogWrite(motorPin0, motorSpeed);
  analogWrite(motorPin1, 0);
}

void spinCounterclockwise() {
  analogWrite(motorPin0, 0);
  analogWrite(motorPin1, motorSpeed);
}
