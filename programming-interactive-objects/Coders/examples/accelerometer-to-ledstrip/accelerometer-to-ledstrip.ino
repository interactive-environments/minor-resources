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

void setup() {
	Serial.begin(9600);
	pixels.begin();
	if (!IMU.begin()) {
		Serial.println("Failed to initialize IMU!");
		while (1);
	}
}

void loop() {

	if (IMU.accelerationAvailable()) {
		IMU.readAcceleration(x, y, z);
	}
	resetMaxMin(x, y, z);
	scaleColor(x, y, z);
	setMatrixColor(red, green, blue);
	// printColor();
	printAccelerometer();
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
