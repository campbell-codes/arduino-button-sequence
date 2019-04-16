// constants won't change. They're used here to set pin numbers:
const int buttonPinA = 2;
const int buttonPinB = 3;
const int buttonPinC = 4;
const int buttonPinD = 5;
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonStateA = 0;         // variable for reading the pushbutton status
int buttonStateB = 0;
int buttonStateC = 0;
int buttonStateD = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinA, INPUT);
  pinMode(buttonPinB, INPUT);
  pinMode(buttonPinC, INPUT);
  pinMode(buttonPinD, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonStateA = digitalRead(buttonPinA);
  buttonStateB = digitalRead(buttonPinB);
  buttonStateC = digitalRead(buttonPinC);
  buttonStateD = digitalRead(buttonPinD);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateA == HIGH || buttonStateB == HIGH || buttonStateC == HIGH || buttonStateD == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
