const int latchPin = 12;//Pin connected to ST_CP of 74HC595
const int clockPin = 8;//Pin connected to SH_CP of 74HC595
const int dataPin = 11; //Pin connected to DS of 74HC595
const int keyIn = 2;  //keyIn attach to
 
const int charCount = 16;
int datArray[charCount] = {
// shift order:   abcdefgp
  252, // char 0: 11111100
  96,  // char 1: 01100000
  218, // char 2: 11011010
  242, // char 3: 11110010
  102, // char 4: 01110010
  182, // char 5: 10110110
  190, // char 6: 10111110
  224, // char 7: 11100000
  254, // char 8: 11111110
  246, // char 9: 11110110
  238, // char A: 11101110
  62,  // char b: 00111110
  158, // char C: 10011110
  122, // char d: 01111010
  158, // char E: 10011110
  142  // char f: 10001110
};

long randNumber;

void setup()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(keyIn,INPUT);
  randomSeed(analogRead(0));
}
/************************************************/
void loop() {
  // wait for user to press button
  while (!digitalRead(keyIn));
  
  for (int i = 0; i <= 9; i++) {
    clearDisplay();
    delay(50);
    randNumber = random(1,6);

    if (i < 9) {
      showNum(randNumber);
    } else {
      showNumWithDot(randNumber);
    }
    delay(100 + (i * 75));
  }

  // ensure user has let go of button
  while (digitalRead(keyIn));
}

void showNum(int num) {
  digitalWrite(latchPin,LOW); //ground latchPin and hold low for as long as you are transmitting
  shiftOut(dataPin, clockPin, MSBFIRST, datArray[num]);
  digitalWrite(latchPin,HIGH); //pull the latchPin to save the data
}

void showNumWithDot(int num) {
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, datArray[num] | B00000001);
  digitalWrite(latchPin,HIGH); //pull the latchPin to save the data
}

void clearDisplay() {
  digitalWrite(latchPin,LOW); //ground latchPin and hold low for as long as you are transmitting
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin,HIGH); //pull the latchPin to save the data
}

