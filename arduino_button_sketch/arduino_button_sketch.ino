// Input pins connected to the buttons
int buttonPins[] = {2, 3, 4, 5};
int buttonPinsCount = sizeof(buttonPins) / sizeof(int);
// Output pin will be high when sequence entered correctly otherwise low
const int outputPin =  13;
// The sequence the buttons must be pressed in to trigger output pin
int sequence[]= {3, 5, 2, 4};
// The time the output pin will remain high after correct sequence entered
int outputTime = 5000;
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
    delay(outputTime);
    digitalWrite(outputPin, LOW);
  }
}
