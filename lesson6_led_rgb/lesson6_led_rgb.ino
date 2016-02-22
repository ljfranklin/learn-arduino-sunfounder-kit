const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int delayTime = 1000;

const byte red[] = {255,0,0};
const byte green[] = {0,255,0};
const byte blue[] = {0,0,255};
const byte orange[] = {237,109,0};
const byte yellow[] = {255,215,0};
const byte indigo[] = {0,46,90};
const byte purple[] = {128,0,128};

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  changeColor(red);
  delay(delayTime);
  changeColor(green);
  delay(delayTime);
  changeColor(blue);
  delay(delayTime);
  changeColor(orange);
  delay(delayTime);
  changeColor(yellow);
  delay(delayTime);
  changeColor(indigo);
  delay(delayTime);
  changeColor(purple);
  delay(delayTime);
}

void changeColor(const byte colorValues[]) {
  analogWrite(redPin, colorValues[0]);
  analogWrite(greenPin, colorValues[1]);
  analogWrite(bluePin, colorValues[2]);
}
