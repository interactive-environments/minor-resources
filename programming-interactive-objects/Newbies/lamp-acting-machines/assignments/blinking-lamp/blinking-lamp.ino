// ---------------------------------------------- Libraries

// ---------------------------------------------- Variables
const int led_pin = 13;         // pin of internal LED
const int button_pin = 2;       // connect a button to D2
const int analog_pin = A0;      // connect a analog sensor to A0

//Timer variables
unsigned long blink_duration = 100;
unsigned long time_mark = 0;

// Acting Machine variables
const int state_off = 0;    
const int state_blink_on = 1;
const int state_blink_off = 2;
int current_state = state_off;  // we start with lamp off

// ---------------------------------------------- Setup and loop
void setup() {
  pinMode(led_pin, OUTPUT);     // setup LED pin properly
  Serial.begin(9600);
}

void loop() {
  updateActingMachine();        // hand control to the Acting Machine
}

// ---------------------------------------------- Acting Machine effect functions
void setLed(boolean state) {
}

void startTimer()
{
  time_mark = millis();
}

// ---------------------------------------------- Acting Machine cause functions
boolean buttonPress() {
}

boolean timerExpired() {
  if (millis() - time_mark > blink_duration) {
    return(true);
  }
  else {
    return(false);
  }
}

// ---------------------------------------------- Acting Machine control flow
void updateActingMachine() {
  switch (current_state) {
    case state_off:
       break;
    case state_blink_on :
      break;
    case state_blink_off :
      break;
  }
}
