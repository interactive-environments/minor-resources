// Pomodoro Acting Machine
// A Pomodoro timer helps a user to structure his/her work activities by mixing focussed
// work with break moments.
// Check: https://en.wikipedia.org/wiki/Pomodoro_Technique
//
// Created September 2019
// By Aadjan van der Helm, Lorenzo Romagnoli & Dieter Vandoren


// ---------------------------------------------- Libraries

// TODO: Add required library include(s)


// ---------------------------------------------- Variables

// TODO: Add the variable(s) the program needs


// Collection of states for Pomodoro Acting Machine (pam)
const int state_idle = 0;
const int state_work = 1;
const int state_break_alarm = 2;
const int state_short_break = 3;
const int state_work_alarm = 4;
const int state_long_break = 5;

// Remember the current state
int current_state = 0;

// Variable for tracking state changes for debugging
int previous_state = state_idle;

// Timer variables
unsigned long timer_duration = 0;
unsigned long time_mark = 0;

// ---------------------------------------------- Setup and loop

void setup () {
  // TODO: Add setup code here
  Serial.begin(9600);
}

void loop () {
  updatePomodoroMachine();
}


// ---------------------------------------------- Acting Machine cause functions

boolean timerExpired() {
  if (millis() - time_mark > timer_duration) {
    return true;
  }
  else {
    return false;
  }
}

// Return true once when button is pressed (moves from up to down state)
boolean buttonPress() {
  return false; // TODO: Return whether condition is true or false
}


// ---------------------------------------------- Acting Machine effect functions

void timerStart(unsigned long duration) {
  timer_duration = duration;
  time_mark = millis();
}

void setLedColor(int r, int g, int b) {
  // TODO: Write code to perform this effect
  //    leds[0].setRGB(i, i, i);
}

void setBuzzer(boolean i) {
  // TODO: Write code to perform this effect
}


// ---------------------------------------------- Acting Machine control flow

void updatePomodoroMachine ()
{
  switch (current_state) {
    // -------------------------------------- State idle
    case state_idle :
      if (buttonPress() == true) {
        timerStart(2000);
        setLedColor(0, 255, 0);
        current_state = state_work;
      }
      break;

    // -------------------------------------- State work
    case state_work :
      if (timerExpired() == true) {
        setBuzzer(true);
        setLedColor(255, 0, 0);
        current_state = state_break_alarm;
      }
      break;

    // -------------------------------------- State break alarm
    case state_break_alarm :
      // TODO: Write code for transitions from this state to others
      break;

    // -------------------------------------- State short break
    case state_short_break :
      // TODO: Write code for transitions from this state to others
      break;

    // -------------------------------------- State work alarm
    case state_work_alarm :
      // TODO: Write code for transitions from this state to others
      break;

    // -------------------------------------- State long break
    case state_long_break :
      // TODO: Write code for transitions from this state to others
      break;
  }
  debugPam();
} // updatePomodoroMachine


// ------------------------------------------- Debug helper function
//
// Prints state change to serial monitor. This is complete. Do not edit.

void debugPam() {
  if (previous_state == current_state)
    return;

  previous_state = current_state;

  switch (current_state) {
    case state_idle :
      Serial.println("state_idle");
      break;
    case state_work :
      Serial.println("state_work");
      break;
    case state_break_alarm :
      Serial.println("state_break_alarm");
      break;
    case state_short_break :
      Serial.println("state_short_break");
      break;
    case state_work_alarm :
      Serial.println("state_work_alarm");
      break;
    case state_long_break :
      Serial.println("state_long_break");
      break;
    default :
      Serial.println("unknown state");
      break;
  }
} // debugPam
