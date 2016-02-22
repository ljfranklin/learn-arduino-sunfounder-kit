int ledPins[] = {2,3,4,5,6,7,8,9};
const int pinCount = 8;
const int delayTime = 50;

void setup() {
  for (int i = 0; i < pinCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < pinCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
  }
  for (int i = 0; i < pinCount; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(delayTime);
  }
}
