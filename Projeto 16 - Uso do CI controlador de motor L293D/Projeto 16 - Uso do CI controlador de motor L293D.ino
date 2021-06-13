//Projeto 16 - Uso do CI controlador de motor L293D
#define switchPin 2 // Entrada da chave
#define motorPin1 3 // Entrada 1 do L293D
#define motorPin2 4 // Entrada 2 do L293D
#define speedPin 9 	// Pino de Ativação 1 do L293D
#define potPin 0 	// Potenciômetro no pino analógico 0
int Mspeed = 0; 	// Uma variável para armazenar o valor de velocidade atual

void setup () {
	// Define o pino da chave como INPUT
	pinMode(switchPin, INPUT);
	
	// Define os pinos remanescentes como saída
	pinMode(motor1, OUTPUT);
	pinMode (motor2, OUTPUT);
	pinMode (speedPin, OUTPUT);
}

void loop() {
	Mspeed = analogRead(potPin)/4;		// Lê o valor de velocidade a partir do potenciômetro
	analogWrite(speedPin, Mspeed);		// Escreve a velocidade para o pino de Ativação 1
	if (digitalRead(switchPin)) {		// Se a chave estiver HIGH, gire o motor em sentido horário
		digitalWrite(motorPin1, LOW); 	// Define a entrada 1 do L293D como baixa
		digitalWrite(motorPin2, HIGH); 	// Define a entrada 2 do L293D como alta
	}
	
	else {	//Se a chave estover LOW, gire o motor em sentido anti-horário
		digitalWrite(motorPin1, HIGH); 	// Define a entrada 1 do L293D como alta
		digitalWrite(motorPin2, LOW); 	// Define a entrada 2 do L293D como baixa
	}
}