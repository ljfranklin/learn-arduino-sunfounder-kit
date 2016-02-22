const int buttonPin = 2;
const int motorIn1 = 9;
const int motorIn2 = 10;
int stat = 0;

const int slowSpeed = 150;
const int mediumSpeed = 200;
const int fastSpeed = 250;

int buttonState;
int lastButtonState = LOW;

// ensure switch does not trigger multiple times on single press
long lastDebounceTime = 0;
long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);
}
 
void loop() {
  int reading = digitalRead(buttonPin);
 
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
   
  if (reading != buttonState && (millis() - lastDebounceTime) > debounceDelay) {
    buttonState = reading;
    if (buttonState == HIGH) {
      stat = stat + 1;
      if(stat >= 4)
      {
        stat = 0;
      }
    }
  }
  
  switch(stat) {
    case 1:
      changeSpeed(slowSpeed);
      break;
    case 2:
      changeSpeed(mediumSpeed);
      break;
    case 3:
      changeSpeed(fastSpeed);
      break;
    default:
      changeSpeed(0);
  }
  lastButtonState = reading;
}

void changeSpeed(int s) {
  //rotate clockwise
  analogWrite(motorIn1, 0);
  analogWrite(motorIn2, s);
}
