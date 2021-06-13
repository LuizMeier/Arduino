// Projeto 14 - Sensor de Luz

int piezoPin = 8; // Piezo no pino 8
int ldrPin = 0; // LDR no pino analógico 0
int ldrValue = 0; // Valor lido do LDR

void setup() {
	// nada a ser feito aqui
}

void loop() {
	ldrValue = analogRead(ldrPin); // Lê o valor do LDR
	tone(piezoPin,1000); // Toca um tom de 1000Hz do piezo
	delay(25); // Espera um pouco
	noTone(piezoPin); // Interrompe o tom
	delay(ldrValue); // Espera a quantidade de milissegundos em ldrValue
}