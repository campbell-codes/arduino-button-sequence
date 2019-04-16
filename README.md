# arduino-button-sequence
An Arduino project which has a set of input buttons and a desired sequence and outputs on a pin when that sequence is entered correctly

## Usage
To use this set the following variables according to your circuit configuration then deploy to arduino.
```
// Input pins connected to the buttons
int buttonPins[] = {2, 3, 4, 5};

// Output pin will be high when sequence entered correctly otherwise low
const int outputPin =  13;

// The sequence the buttons must be pressed in to trigger output pin
int sequence[]= {3, 5, 2, 4};

// The time the output pin will remain high after correct sequence entered
int outputTime = 5000;
```
The configuration in the code above has the buttons connected to digital pins 2, 3, 4 & 5. The output pin as 13 (LED). The sequence the buttons should be pressed as 3 then 5 then 2 then 4. The time the output should be HIGH as 5 seconds.
