const int buttonPin = 12;
const int ledPin = 13;

void setup() {
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
