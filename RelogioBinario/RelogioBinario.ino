#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

int ledPins[] = {0,1,6,7,8,9};

void setup() { 
  lcd.begin(16, 2);
  
  for (int thisPin =0; thisPin < 6; thisPin++) {
   pinMode(ledPins[thisPin], OUTPUT); 
  }
}

void loop() { 
  for (int segundo = 0 ; segundo < 60 ; segundo++) {
    digitalWrite(9, HIGH && (segundo & B00100000));
    digitalWrite(8, HIGH && (segundo & B00010000));
    digitalWrite(7, HIGH && (segundo & B00001000));
    digitalWrite(6, HIGH && (segundo & B00000100));
    digitalWrite(1, HIGH && (segundo & B00000010));
    digitalWrite(0, HIGH && (segundo & B00000001));
    
    // Trata a saida
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(segundo,BIN);
    delay(1000);
  }
}
