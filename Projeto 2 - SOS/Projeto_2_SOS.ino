// Projeto 2 - SOS

// LED conectado ao pino 10
int ledPin = 10;

// Executa uma vez, quando o sketch inicia
void setup ()
{
  // Define o pino como saída
  pinMode(ledPin, OUTPUT);
}

// Executa repetidas vezes
void loop()
{
  
  // 3 pontos
  for (int x=0; x<3; x++)
  {
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(150);                 // espera 150ms
    digitalWrite(ledPin, LOW);  // apaga o LED
    delay(100);                 // espera 100ms
  }
  
  // Espera 100ms para marcar o intervalo entre as letras
  delay (100);
  
  // 3 traços
  for (int x=0; x<3; x++)
  {
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(400);                 // espera 400ms
    digitalWrite(ledPin, LOW);  // apaga o LED
    delay(100);                 // espera 100ms
  }
  // Espera 100ms para marcar o intervalo entre as letras
  delay (100);
  
  // 3 pontos novamente
  for (int x=0; x<3; x++)
  {
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(150);                 // espera 150ms
    digitalWrite(ledPin, LOW);  // apaga o LED
    delay(100);                 // espera 100ms
  }
  // Espera 5s antes de repetir o sinal de SOS
  delay (5000);
}
