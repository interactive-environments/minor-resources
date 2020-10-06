// ---------------------------------------------- Libraries

// ---------------------------------------------- Variables
const int led_pin = 13;         // pin of internal LED
const int button_pin = 2;       // connect a button to D2
const int analog_pin = A0;      // connect a analog sensor to A0

// Acting Machine Variables
const int state_off = 0;    
const int state_on = 1;
int current_state = state_off;  // we start with lamp off

// ---------------------------------------------- Setup and loop
void setup() {
  pinMode(led_pin, OUTPUT);     // setup LED pin properly
}

void loop() {
  updateActingMachine();        // hand control to the Acting Machine
}

// ---------------------------------------------- Acting Machine effect functions
void switchLamp(boolean state) {
  // Use the Arduino API calls to control the internal LED on pin led_pin
}

// ---------------------------------------------- Acting Machine cause functions
boolean buttonPress() {
  // Use the Arduino API calls to check user input on pin button_pin or analog_pin
}

// ---------------------------------------------- Acting Machine control flow
void updateActingMachine() {
  switch (current_state) {
    case state_off:
      if (buttonPress() == true) {
        switchLamp(true);
        current_state = state_on;
      }
      break;
    case state_on :
      if (buttonPress() == true) {
        switchLamp(false);
        current_state = state_off;
      }
      break;
  }
}
