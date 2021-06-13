#include <LiquidCrystal.h>

// start LCD object
LiquidCrystal lcd(11, 10, 9, 8, 7, 6);

int latchPinMin = 2;
int clockPinMin = 0;
int dataPinMin = 1;
int latchPinHr = 5;
int clockPinHr = 3;
int dataPinHr = 4;
int second = 0;
int minute = 0;
int hour = 0;
int inform = 12;
int confirm = 13;

void setup() {
  
	//sets the LCD
	lcd.begin(16,2);
	
	//set pins to output so you can control the shift register
	pinMode(latchPinMin, OUTPUT);
	pinMode(clockPinMin, OUTPUT);
	pinMode(dataPinMin, OUTPUT);
	pinMode(latchPinHr, OUTPUT);
	pinMode(clockPinHr, OUTPUT);
	pinMode(dataPinHr, OUTPUT);
	
	// sets the button pin as input
	pinMode(inform, INPUT);
	pinMode(confirm, INPUT)
	
	imprime();
}

void loop() {
	
	// read the button status
	val = digitalRead(inform);
	
	// if button pressed, calls the setup
	if (val == HIGH) {
		configClock()
	}
	
	// set up a local variable to hold the last time we moved forward one second
	// (static variables are initialized once and keep their values between function calls)
	static unsigned long lastTick = 0; 
	
	// move forward one second every 1000 milliseconds
	if (millis() - lastTick >= 1000) {
		lastTick = millis();
		second++;
		imprime();
	}
	
	// move forward one minute every 60 seconds
	if (second >= 2) {
		minute++;
		second = 0; // reset seconds to zero
	}
	
	// move forward one hour every 60 minutes
	if (minute >=60) {
		hour++;
		
		// take the latchPin low so 
		// the LEDs don't change while you're sending in bits:
		digitalWrite(latchPinMin, LOW);
		
		// shift out the bits:
		shiftOut(dataPinMin, clockPinMin, LSBFIRST, minute);
		
		// take the latch pin high so the LEDs will light up:
		digitalWrite(latchPinMin, HIGH);
		
		minute = 0; // reset minutes to zero
	}
	
	if (hour >=24) {
		digitalWrite(latchPinHr, LOW);
		shiftOut(dataPinHr, clockPinHr, LSBFIRST, hour);
		digitalWrite(latchPinHr, HIGH);
		
		hour=0; // reset hour to zero
		minute = 0; // reset minutes to zero
	}

}

void imprime () {
	// print the values
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Hora atual:");
	lcd.setCursor(0,1);
	lcd.print(hour);
	lcd.print(":");
	lcd.print(minute);
	lcd.print(":");
	lcd.print(second);
}

void configClock () {
	int informNow = 0;
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Informe a hora:");
	lcd.setCursor(0,1);
	
	// adjust hours
	while (confirm != HIGH) {
		if(inform == HIGH) {
			if (informNow >= 24) {
				informNow = 0;
			}
			inform++
			hour = informNow;
			lcd.print(informNow);
		}
	}
	
	// adjust minutes
	while (confirm != HIGH) {
		if(inform == HIGH) {
			if (informNow >= 24) {
				informNow = 0;
			}
			inform++
			minute = informNow;
			lcd.print(informNow);
		}
	}