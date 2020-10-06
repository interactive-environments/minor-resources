// ---------------------------------------------- Libraries

// ---------------------------------------------- Variables
const int led_pin = 13;           // pin of internal LED
const int button_pin = 2;         // connect a button to D2
const int analog_pin = A0;        // connect a analog sensor to A0
int previous_button_state = LOW; // remember what the button state was in the previous loop
int intensity = 0;

//Timer variables
unsigned long blink_duration = 100;
unsigned long time_mark = 0;

// Acting Machine variables
const int state_off = 0;    
const int state_fade_on = 1;
const int state_fade_off = 2;
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
void setLed(int intensity) {
  leds.setColorRGB(0, intensity, intensity, intensity);
  if (state == true) {
    digitalWrite(led_pin, HIGH);
  }
  else {
    digitalWrite(led_pin, LOW);
  }
}

void startTimer()
{
  time_mark = millis();
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
      if (buttonPress() == true) {
        setLed(true);
        startTimer();
        current_state = state_blink_on;
      }
      break;
    case state_fade_on :
      if (timerExpired() == true) {
        intensity = intensity + 2;
        setLed(intensity);
        startTimer();
      }
      if (intensity > 255) {
       startTimer();
        current_state = state_fade_off;        
      }
      if (buttonPress() == true) {
        setLed(false);
        current_state = state_off;
      }
      break;
    case state_fade_off :
      if (timerExpired() == true) {
        setLed(true);
        startTimer();
        current_state = state_fade_on;
      }
      if (buttonPress() == true) {
        setLed(false);
        current_state = state_off;
      }
      break;
  }
}
