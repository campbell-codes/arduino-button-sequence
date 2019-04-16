int buttonPins[] = {2, 3, 4, 5};
int buttonPinsCount = sizeof(buttonPins) / sizeof(int);
const int outputPin =  13;
int sequence[]= {3, 5, 2, 4};
int sequenceCount = sizeof(sequence) / sizeof(int);
int correctGuesses = 0;
int lastInputPin = -1;

void setup() {
  for(int i=0; i < buttonPinsCount; i++){
    pinMode(buttonPins[i], INPUT);
  }
  pinMode(outputPin, OUTPUT);
}

void loop() {
  for(int i=0; i < buttonPinsCount; i++){
    int pin = buttonPins[i];
    int pinState = digitalRead(pin);
    // Check if pin HIGH and that it's not the same pin we got last time (they are holding the button)
    // This means the sequence won't reset if someone tries the same button twice
    if (pinState == HIGH && pin != lastInputPin){
      lastInputPin = pin;
      if (pin == sequence[correctGuesses]){
        correctGuesses++;
      } else{
        correctGuesses = 0;
      }
      break;
    }
  }
  if (correctGuesses == sequenceCount){
    correctGuesses = 0;
    digitalWrite(outputPin, HIGH);
    delay(5000);
    digitalWrite(outputPin, LOW);
  }
}
