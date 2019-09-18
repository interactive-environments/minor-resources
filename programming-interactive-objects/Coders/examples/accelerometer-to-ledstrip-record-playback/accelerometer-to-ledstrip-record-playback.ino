#include <Arduino_LSM6DS3.h>

#include <Adafruit_NeoPixel.h>
#define PIN            6
#define NUMPIXELS      64

float maxVal = 0;
float minVal = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

int red = 0;
int green = 0;
int blue = 0;

float x, y, z;

float recordedX [1000];
float recordedY [1000];
float recordedZ [1000];

int buttonPin = A0;

long lastUpdated;
int animationIndex = 0;
int interval = 1;

int buttonPressed;
int lastButtonPressed = false;

boolean isrecording = false;

void setup() {
  Serial.begin(9600);
  pixels.begin();
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  pinMode(buttonPin, INPUT);
//  pixels.setBrightness(50);

}

void loop() {

  if (millis() - lastUpdated > interval) {
    animationIndex++;
    if (animationIndex == 1000) {
      animationIndex = 0;
    }
    Serial.println(animationIndex);
    buttonPressed = digitalRead(buttonPin);

    if (buttonPressed && !lastButtonPressed) {
      isrecording = true;
      animationIndex = 0;

    } else if (!buttonPressed && lastButtonPressed) {
      isrecording = false;
    }

    if (isrecording) {
      if (IMU.accelerationAvailable()) {
        IMU.readAcceleration(x, y, z);
      }
      resetMaxMin(x, y, z);
      scaleColor(x, y, z);
      recordValues(red, green, blue);
      //setMatrixColor(x, y, z);
      setWhiteBrightness(red, green, blue);
    } else {
      setMatrixColor(recordedX[animationIndex], recordedY[animationIndex], recordedZ[animationIndex]);
      setWhiteBrightness(recordedX[animationIndex], recordedY[animationIndex], recordedZ[animationIndex]);
    }
    lastUpdated=millis();
  }
  lastButtonPressed = buttonPressed;
}


// setMatrixColor(red, green, blue);
// printColor();
// printAccelerometer();


void recordValues(int x, int y, int z) {
  for (int i = 0; i < 1000 - 1; i++) {
    recordedX[i] = recordedX[i + 1];
    recordedY[i] = recordedY[i + 1];
    recordedZ[i] = recordedZ[i + 1];
  }
  recordedX[1000 - 1] = x;
  recordedY[1000 - 1] = y;
  recordedZ[1000 - 1] = z;
}

void setMatrixColor(int r, int g, int b) {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.show();
}

void resetMaxMin(float x, float y, float z) {
  if (x > maxVal) {
    maxVal = x;
  } else if (y > maxVal) {
    maxVal = y;
  } else if (z > maxVal) {
    maxVal = z;
  } else if (x < minVal) {
    minVal = x;
  } else if (y > minVal) {
    minVal = y;
  } else if (z > minVal) {
    minVal = z;
  }
}

void scaleColor(int x, int y, int z) {
  red = map(x, minVal, maxVal, 0, 255);
  green = map(y, minVal, maxVal, 0, 255);
  blue = map(z, minVal, maxVal, 0, 255);
}

void printColor() {
  Serial.print(red);
  Serial.print(",");
  Serial.print(green);
  Serial.print(",");
  Serial.println(blue);
}


void printAccelerometer() {
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.println(z);
}

void setWhiteBrightness(int x, int y, int z) {
  int sum = abs(x) + abs(y) + abs(z);
  sum = map (sum, 0, 255 * 3, 0, 100);
  
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(sum, sum, sum));
  }
  pixels.show();

}
