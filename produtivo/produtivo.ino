// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            4

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      45

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ400);

int delayval = 500; // delay for half a second

const int botao = 8;

int estadoBotao = 0;
int ultimoEstado = 0;
int contagemBotao = 0;

void setup() {
  Serial.begin(9600) ;
  pixels.begin(); // This initializes the NeoPixel library.
  pinMode(botao, INPUT);
}

void loop() {
  // Verifica o estado do botão
  estadoBotao = digitalRead(botao);

  // Compara o estado do botão
  if (estadoBotao != ultimoEstado) {
     if (estadoBotao == HIGH) {
      // Se tiver apertado, incrementa
      contagemBotao++;
      Serial.println("on");
      Serial.println(contagemBotao);
      if (contagemBotao > 7) {
        contagemBotao = 0;
      }
     }
     else {
      Serial.println("off");
     }
//      delay (50);
  }
  ultimoEstado = estadoBotao;

  //Se botão for 1, vermelho
  if (contagemBotao == 1) {
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(255,0,0)); // Preenche as cores
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
  }
    
   //Se botão for 2, laranja
  if (contagemBotao == 2) {
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(255,127,0)); // Preenche as cores
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
  }  
  
  //Se botão for 3, amarelo
  if (contagemBotao == 3) {
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(255,255,0)); // Preenche as cores
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
  }
    
   //Se botão for 4, verde
  if (contagemBotao == 4) {
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,255,0)); // Preenche as cores
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
  }  

   //Se botão for 5, azul
  if (contagemBotao == 5) {
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,255)); // Preenche as cores
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
  }  

  //Se botão for 6, roxo
  if (contagemBotao == 6) {
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(75,0,130)); // Preenche as cores
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
  }

    //Se botão for 7, lilás
  if (contagemBotao == 6) {
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(143,0,255)); // Preenche as cores
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
  }
}


