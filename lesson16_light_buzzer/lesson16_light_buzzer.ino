
// couldn't get this lesson to work

const int buzzerPin = 5;
const int ledPin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(5,OUTPUT);
}

void loop() {
  int n = analogRead(A0);
  Serial.println(n);
  if (n > 0) {
    tone(buzzerPin, 10000); // 10000 Hz (and 50% duty cycle)
  }
}
