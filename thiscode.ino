// aTHALLAH jOYONINGRAT / 123230230 / iF-h

const int redPin = 12, greenPin = 10, bluePin = 11, buttonPin = 2;
const int segA = 3, segB = 4, segC = 5, segD = 6, segE = 7, segF = 8, segG = 9, segDP = 13;
const int segmentPins[] = {segA, segB, segC, segD, segE, segF, segG};

int stateCounter = 5;
int lastButtonState = HIGH;

const byte digitPatterns[10][7] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW },  // 0
  {LOW,  HIGH, HIGH, LOW,  LOW,  LOW,  LOW },  // 1
  {HIGH, HIGH, LOW,  HIGH, HIGH, LOW,  HIGH},  // 2
  {HIGH, HIGH, HIGH, HIGH, LOW,  LOW,  HIGH},  // 3
  {LOW,  HIGH, HIGH, LOW,  LOW,  HIGH, HIGH},  // 4
  {HIGH, LOW,  HIGH, HIGH, LOW,  HIGH, HIGH},  // 5
  {HIGH, LOW,  HIGH, HIGH, HIGH, HIGH, HIGH},  // 6
  {HIGH, HIGH, HIGH, LOW,  LOW,  LOW,  LOW },  // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},  // 8
  {HIGH, HIGH, HIGH, HIGH, LOW,  HIGH, HIGH}   // 9
};

const bool rgbStates[6][3] = {
  {HIGH, LOW,  LOW}, {LOW,  HIGH, LOW}, {LOW,  LOW,  HIGH}, // Merah, Hijau, Biru
  {HIGH, HIGH, LOW}, {HIGH, LOW,  HIGH}, {LOW,  HIGH, HIGH}  // Kuning, Magenta, Cyan
};

const int nimDigits[] = {2, 3, 0};

void setup() {
  pinMode(redPin, OUTPUT); pinMode(greenPin, OUTPUT); pinMode(bluePin, OUTPUT);
  pinMode(segDP, OUTPUT);
  for (int i = 0; i < 7; i++) { pinMode(segmentPins[i], OUTPUT); }
  pinMode(buttonPin, INPUT_PULLUP);
  
  allOff();
  lastButtonState = digitalRead(buttonPin);
}

void loop() {
  int currentState = digitalRead(buttonPin);

  // Jika tombol BARU SAJA ditekan (transisi dari LOW ke HIGH)
  if (currentState == HIGH && lastButtonState == LOW) {
    stateCounter = (stateCounter + 1) % 6;
  }

  // Jika tombol SEDANG DITAHAN (level HIGH)
  if (currentState == HIGH) {
    setRGBColorAndDigit(stateCounter);
  } else {
  // Jika tombol SEDANG DILEPAS (level LOW)
    allOff();
  }

  lastButtonState = currentState;
}

void setRGBColorAndDigit(int state) {
  digitalWrite(redPin,   rgbStates[state][0]);
  digitalWrite(greenPin, rgbStates[state][1]);
  digitalWrite(bluePin,  rgbStates[state][2]);

  if (state >= 3) { // Kuning, Magenta, atau Cyan
    digitalWrite(segDP, HIGH);
    int digitToShow = nimDigits[state - 3]; // state 3->digit 0, state 4->digit 1, dst.
    displayDigit(digitToShow);
  } else {
    digitalWrite(segDP, LOW);
  }
}

void displayDigit(int digit) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[digit][i]);
  }
}

void allOff() {
  for (int i = 0; i < 7; i++) { digitalWrite(segmentPins[i], LOW); }
  digitalWrite(segDP, LOW);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}
