const int ledPin = 9;
const int potPin = A0;

int potValue = 0;
int adjustedPotValue = 0;

void setup() {
  // setting pinMode is not required for analogRead/Write
}

void loop() {
  potValue = analogRead(potPin);
  adjustedPotValue = map(potValue,0,1023,0,255);
  analogWrite(ledPin, adjustedPotValue);
}
