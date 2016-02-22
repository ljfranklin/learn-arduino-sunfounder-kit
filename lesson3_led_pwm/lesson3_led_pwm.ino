const int ledPin = 9;

void setup() {
  pinMode(ledPin,OUTPUT);
}

void loop() {
  for (int a=0; a<=255;a++) {
    analogWrite(ledPin, a);
    delay(8);
  }
  for (int a=255; a>=0;a--) {
    analogWrite(ledPin, a);
    delay(8);
  }
  delay(800);
}
