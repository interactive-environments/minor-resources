# Programming interactive objects
## introduction to small Arduinos & Mqtt networking


### prerequisites
students joining this class should already be familiar with:
- Arduino programming
- Digital/Analogue Read/Write

### Goal of the class
The class will focus on:
 - Getting familiar with an Arduino Bard with WiFi capabilities
 - Familiarize with mqtt protocol and shiftr.io using a microcontroller
 - Familiarize with Led matrixes programming and discover advanced expression capabilities
 - Express ecologies behaviours

## LETS START!

For the workshop we are going to use a [Arduino nano 33 IOT](https://store.arduino.cc/nano-33-iot)
**MAIN FEATURES**:
- Arm Cortex-M0+ SAMD21 processor 
- WiFi and Bluetooth module based on ESP32
- LSM6DS3 IMU (ACCELEROMETER + MAGNETOMETER + GYRO)

### TASK 1
Follow the getting started guide on the Arduino website [here](https://www.arduino.cc/en/Guide/NANO33IoT) and install the Arduino SAMD core.
Try uploading a blink firmware to the board to verify that it works.

### TASK 2
Using the Library manager install the following libraries:
- [wifiNina](https://github.com/arduino-libraries/WiFiNINA)
- [arduino-mqtt](https://github.com/256dpi/arduino-mqtt)
- [Adafruit NeoPixel Library](https://github.com/adafruit/Adafruit_NeoPixel)

Optionally, to access the IMU data and run advanced animations on the matrix install those additional libraries:
- [LSM6DS3 Library for Arduino](https://github.com/arduino-libraries/Arduino_LSM6DS3)
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit_NeoMatrix](https://github.com/adafruit/Adafruit_NeoMatrix)

### TASK 3
Connect to shiftr.io
You can find a working code example [here](https://github.com/id-studiolab/Mqtt-Connection-resources/blob/master/Arduino/Nano32_IOT_shitr.io/Nano32_IOT_shitr.io.ino)

### TASK 4
Try the accelerometer example and explore the serial plotter

### TASK 5
Transform movements into light
Use the on board accelerometer to measuere and capture one movement

### TASK 6
Can you record a moveemnt and then play it back trough light?
