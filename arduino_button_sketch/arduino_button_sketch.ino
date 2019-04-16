int buttonPins[] = {2, 3, 4, 5};
int buttonPinsCount = 4;
const int outputPin =  13;
int sequence[]= {3, 5, 2, 4};
int correctGuesses = 0;

void setup() {
  for(int i=0; i < buttonPinsCount; i++){
    pinMode(buttonPins[i], INPUT);
  }
  pinMode(outputPin, OUTPUT);
}

void loop() {
  bool inputRegistered = false;
  for(int i=0; i < buttonPinsCount; i++){
    int pin = buttonPins[i];
    int pinState = digitalRead(pin);
    if (pinState == HIGH){
      digitalWrite(outputPin, HIGH);
      inputRegistered = true;
      break;
    }
  }
  
  if(!inputRegistered){
    digitalWrite(outputPin, LOW);
  }
}
