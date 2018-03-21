#include <NintendoExtensionCtrl.h>

Nunchuk nchuk;

void setup() {
	Serial.begin(115200);
	nchuk.begin();
}

void loop() {
	boolean success = nchuk.update();  // Get new data from the controller

	if (success == true) {  // We've got data!
		nchuk.printDebug();  // Print all of the values!
	}
	else {  // Data is bad :(
		Serial.println("Controller Disconnected!");
		nchuk.reconnect();
	}
}
