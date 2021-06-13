#include <AFMotor.h>

// Projeto 29 - Uso de um shield de motor

// Define os pinos de velocidade e direção de cada motor
int speed1 = 5;
int speed2 = 6;
int direction1 = 12;
int direction2 = 13;

void stopMotor(){
  // desliga ambos os motores
  analogWrite(speed1, 0);
  analogWrite(speed2, 0);
}

void setup() {
  // define todos os pinos como saídas
  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);
  pinMode(direction1, OUTPUT);
  pinMode(direction2, OUTPUT);
}

void loop() {
  // Ambos os motores para frente, com 50% da velocidade, por 2 segundos
  digitalWrite(direction1, HIGH);
  digitalWrite(direction2, HIGH);
  analogWrite(speed1, 128);
  analogWrite(speed2, 128);
  delay(2000);

  stopMotor(); delay(1000); //para

  // Vira para a esquerda por 1 segundo
  digitalWrite(direction1, LOW);
  digitalWrite(direction2, HIGH);
  analogWrite(speed1, 128);
  analogWrite(speed2, 128);
  delay(1000);

  stopMotor(); delay(1000); // para

  // Ambos os motores para a frente, com 50% da velocidade, por 2 segundos
  digitalWrite(direction1, HIGH);
  digitalWrite(direction2, HIGH);
  analogWrite(speed1, 128);
  analogWrite(speed2, 128);
  delay(2000);

  stopMotor(); delay(1000); // para

  // Vira para a direita, com 25% da velocidade
  digitalWrite(direction1, HIGH);
  digitalWrite(direction2, LOW);
  analogWrite(speed1, 64);
  analogWrite(speed2, 64);
  delay(2000);

  stopMotor(); delay(1000); // para
}
