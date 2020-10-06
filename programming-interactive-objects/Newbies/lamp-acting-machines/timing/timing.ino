// Libraries

// Variables
unsigned long pasta_duration = 4000;
unsigned long pasta_time_mark = 0;
unsigned long meatball_duration = 2000;
unsigned long meatball_time_mark = 0;

void setup() {
  Serial.begin(9600);
  startPastaTimer();
  startMeatballTimer();
}

void loop() {
  if (pastaTimerExpired() == true) {
    Serial.println("Pasta");
    startPastaTimer();
  }

  if (meatballTimerExpired() == true) {
    Serial.println("Meatball");
    startMeatballTimer();
  }
}

// Effect
void startPastaTimer() {
  pasta_time_mark = millis();
}
void startMeatballTimer() {
  meatball_time_mark = millis();
}

// Cause
boolean pastaTimerExpired() {
  if (millis() - pasta_time_mark > pasta_duration) {
    return (true);
  }
  else {
    return (false);
  }
}

boolean meatballTimerExpired() {
  if (millis() - meatball_time_mark > meatball_duration) {
    return (true);
  }
  else {
    return (false);
  }
}
// timer_mark 2013
// millis 2011
