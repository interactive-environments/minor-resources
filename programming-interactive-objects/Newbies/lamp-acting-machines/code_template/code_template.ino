// ---------------------------------------------- Libraries

// ---------------------------------------------- Variables
const int state_off = 0;
const int state_on = 1;
int current_state = state_off;

// ---------------------------------------------- Setup and loop
void setup() {

}

void loop() {
  updateActingMachine();
}

// ---------------------------------------------- Acting Machine effect functions

// ---------------------------------------------- Acting Machine cause functions

// ---------------------------------------------- Acting Machine control flow
// Acting Machine control flow
void updateActingMachine() {
  switch (current_state) {
    case state_off :
      // check causes of transitions from state_off
      break;
    case state_on :
       // check causes of transitions from state_on
     break;
  }
}
