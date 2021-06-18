#include <Adafruit_NeoPixel.h>

#define PIN 2	 // input pin Neopixel is attached to

#define NUMPIXELS      4 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int buttonState = 0;
int buttonCount = 0;


void setup() {
  // Initialize the NeoPixel library.
  pixels.begin();
  
  // Setup button
  pinMode (1, INPUT);
  
}


void loop() {
	
	buttonState = digitalRead(1);
	
	if (buttonState == HIGH) {
	  buttonCount = buttonCount + 1;
	}
	
	// Green
	if (buttonCount == 1) {
		redColor = 0;
		greenColor = 255;
		blueColor = 0;
	}
	
	// Blue
	else if (buttonCount == 2) {
		redColor = 0;
		greenColor = 0;
		blueColor = 255;
	}
	
	// Red
	else if (buttonCount == 3) {
		redColor = 255;
		greenColor = 0;
		blueColor = 0;
	}

	// Yellow
	else if (buttonCount == 4) {
		redColor = 255;
		greenColor = 255;
		blueColor = 0;
	}

	// Cyan
	else if (buttonCount == 5) {
		redColor = 0;
		greenColor = 255;
		blueColor = 255;
	}

	// Magenta
	else if (buttonCount == 6) {
		redColor = 255;
		greenColor = 0;
		blueColor = 255;
	}

	// White
	else if (buttonCount == 7) {
		redColor = 255;
		greenColor = 255;
		blueColor = 255;
	}

	// Off
	else if (buttonCount == 8) {
		redColor = 255;
		greenColor = 0;
		blueColor = 0;
	}
	
	else {
	  buttonCount = 0;
	}

  for (int i=0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

    // This sends the updated pixel color to the hardware.
    pixels.show();

    // Delay for a period of time (in milliseconds).
    delay(delayval);
  }



}