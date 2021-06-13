// Projeto 15 - Controle de um motor simples

int potPin = 0; 		// Analógico no 0, conectado ao potenciômetro
int transistorPin = 9; 	// Pino PWM 9 conectado à base do transistor
int potValue = 0; 		// Valor retornado do potenciômetro

void setup() {
	// define o pino do transistor como saída:
	pinMode(transistorPin, OUTPUT);
}

void loop() {
	// lê o potenciômetro, converte para o intervalo de 0 a 255:
	potValue = analogRead(potPin) / 4;
	// utilize isso para controlar o transistor:
	analogWrite(transistorPin, potValue);
}