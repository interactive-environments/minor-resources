// 
// ---------------------------------------------- Libraries
#include <ChainableLED.h>

// ---------------------------------------------- Variables
const int led_pin = 13;           // pin of internal LED
const int button_pin = 2;         // connect a button to D2
const int analog_pin = A0;        // connect a analog sensor to A0
int previous_button_state = LOW;  // remember what the button state was in the previous loop

// Variables for the Grove Chainable LED on pin D7
const int num_leds = 1;
ChainableLED leds(7, 8, num_leds);

const int state_off = 0;    
const int state_red = 1;
const int state_green = 2;
const int state_blue = 3;
int current_state = state_off;  // we start with lamp off

// ---------------------------------------------- Setup and loop
void setup() {
  setLedBlack();                // make the Chainable LED initially black
  Serial.begin(9600);
 }

void loop() {
  updateActingMachine();        // hand control to the Acting Machine
}

// ---------------------------------------------- Acting Machine effect functions
void setLedBlack() {
  leds.setColorRGB(0, 0, 0, 0);
}

void setLedRed() {
  leds.setColorRGB(0, 255, 0, 0);
}

// ---------------------------------------------- Acting Machine cause functions
boolean buttonPress() {
boolean button_down = false;
int current_button_state = digitalRead(button_pin);

  if ((current_button_state == HIGH) && (previous_button_state == LOW)){
    button_down = true;
  }
  previous_button_state = current_button_state;
  return(button_down);
}

// ---------------------------------------------- Acting Machine control flow
void updateActingMachine() {
  switch (current_state) {
    case state_off:
      if (buttonPress() == true) {
        setLedRed();
      }
      break;
    case state_red :
       break;
     case state_green :
      break;
     case state_blue :
      break;
  }
}
