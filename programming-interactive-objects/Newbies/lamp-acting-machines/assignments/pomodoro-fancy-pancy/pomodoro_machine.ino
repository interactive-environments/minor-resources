// Pomodoro Acting Machine (PAM)
// A Pomodoro timer helps a user to structure his/her work activities by mixing focussed
// work with break moments.
// Check: https://en.wikipedia.org/wiki/Pomodoro_Technique
//
// Created December 2018, Modified July 2019
// By Aadjan van der Helm & Lorenzo Romagnoli

// Collection of states for Pomodoro Acting Machine (pam)
const int pam_state_idle = 0;
const int pam_state_work = 1;
const int pam_state_break_alarm = 2;
const int pam_state_short_break = 3;
const int pam_state_work_alarm = 4;
const int pam_state_long_break = 5;

// Remember the current state
int pam_current_state = 0;

// Make it possible to track the passing of time
long pam_timer_duration = 1000;
long pam_timer_mark = 0;

// Variable to remember the previous button state
boolean last_button_state = false;
int button_pin = 2;

// Count the number of short breaks
int break_counter = 0;

// ---------------------------------------------- Acting Machine cause functions

boolean pamTimerExpired() {
  return false; // make it your own
}

// Return true once when button is pressed (moves from up to down state)
boolean buttonPress() {
  return false; // make it your own
}

// ---------------------------------------------- Acting Machine effect functions

void pamTimerStart(long duration) {
  //make it your own;
}

// ---------------------------------------------- Acting Machine utility functions

void setupPomodoroMachine() {
	// Nothing to setup
}

// ---------------------------------------------- Acting Machine control flow
void updatePomodoroMachine ()
{
	switch (pam_current_state) {			
		// -------------------------------------- State idle
    case pam_state_idle :
			break;
			
		// -------------------------------------- State work
		case pam_state_work :
			break;
			
		// -------------------------------------- State break alarm
		case pam_state_break_alarm :
			break;

		// -------------------------------------- State short break
		case pam_state_short_break :
			break;
			
		// -------------------------------------- State work alarm
		case pam_state_work_alarm :
			break;
			
		// -------------------------------------- State long break
		case pam_state_long_break :
			break;
	}
	debugPam();
} // updatePomodoroMachine

int pam_previous_state = pam_state_idle;
void debugPam() {
	if (pam_previous_state == pam_current_state)
		return;
	
	pam_previous_state = pam_current_state;
	
	switch (pam_current_state) {
		case pam_state_idle :
			Serial.println("pam_state_idle");
			break;
		case pam_state_work :
			Serial.println("pam_state_work");
			break;
		case pam_state_break_alarm :
			Serial.println("pam_state_break_alarm");
			break;
		case pam_state_short_break :
			Serial.println("pam_state_short_break");
			break;
		case pam_state_work_alarm :
			Serial.println("pam_state_work_alarm");
			break;
		case pam_state_long_break :
			Serial.println("pam_state_long_break");
			break;
		default :
			Serial.println("unknown state");
			break;
	} 
} // debugPam
