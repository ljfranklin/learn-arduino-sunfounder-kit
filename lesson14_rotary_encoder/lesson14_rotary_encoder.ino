const int clkPin= 2;
const int dtPin= 3;
const int swPin= 4;
 
int encoderVal = 0;
int oldA = HIGH;
 
void setup() {
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
  Serial.begin(9600);
}
 
void loop() {
  int change = getEncoderTurn();
  encoderVal = encoderVal + change;
  if(digitalRead(swPin) == LOW) {
    encoderVal = 0;
  }
  Serial.println(encoderVal);
}
 
int getEncoderTurn() {
  int result = 0;
  int newA = digitalRead(clkPin);
  if (oldA == HIGH && newA == LOW) {
    int bVal = digitalRead(dtPin);
    result = (bVal == HIGH) ? 1 : -1; 
  }
  oldA = newA;
  return result;
}
