#include "Arduino.h"

void setup() {
	// Initialize the serial port
	Serial.begin(115200);
}

void loop() {
	// Print to the serial port
	Serial.println("Hello, World!");
	// Wait 5 seconds (then loop)
	delay(5000);
}
