#include <Adafruit_NeoPixel.h>
#define LED_CTL 4 
#define LED_COUNT 120
Adafruit_NeoPixel strip(LED_COUNT, LED_CTL, NEO_GRB + NEO_KHZ800);

int brightness = 0;
int count = strip.numPixels();
void setup() {
	strip.begin();
	strip.setBrightness(254);
	wipe(35, strip.Color(255, 0, 0), false);
	wipe(35, strip.Color(0, 0, 0), true);
	Serial.begin(9600);
}
void loop() {
	//wipe(35, strip.Color(255, 0, 0), false);
	//wipe(35, strip.Color(0, 255, 0), true);
	//wipe(35, strip.Color(0, 0, 255), false);
  	//wipe(35, strip.Color(100, 50, 200), true);
  	while(Serial.available() > 0){
		byte buffer [Serial.available()]; 
		switch (Serial.available()) {
			case 5:
				Serial.println("Buffer of 5");
				break;
		}
		Serial.readBytesUntil('\xff', buffer, 20);
		wipe(buffer[3], strip.Color(buffer[0], buffer[1], buffer[2]), true);
	}
}
void wipe(int wait, uint32_t color, bool reverse) {
	if(!reverse){
		for(int i=0; i<strip.numPixels(); i++){
			strip.setPixelColor(i, color);
			strip.show();
			delay(wait);
		}
	} else {
		for(int i = strip.numPixels(); i >= 0; i--){
			strip.setPixelColor(i, color);
			strip.show();
			delay(wait);
		}
	}
}
