//Projeto 5.1 - Efeito de iluminação sequencial com LEDs (LED's quicando)
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // Cria um array para os pinos dos LEDs.
int ledDelay(500); //intervalo entre as alterações
int direction = 1;
int currentLED = 0;
unsigned long changeTime;

void setup()
{
  for (int x=0; x<10; x++) // define todos os pinos como saída
  {
    pinMode(ledPin[x], OUTPUT);
  }
  changeTime = millis();
}

void changeLED()
{
  for (int x=0; x<10; x++)
  {
    digitalWrite(ledPin[x], LOW); //apaga todos os LEDs.
  }
  digitalWrite(ledPin[currentLED], HIGH); //acende os LED atuais
  delay(500);
  digitalWrite(ledPin[currentLED], LOW); //acende os LED atuais
  digitalWrite(ledPin[0], HIGH); //acende o led 0.
  delay(500);
  currentLED = currentLED + direction; //decrementa de acordo com o valor de direction
  if (currentLED == 9) {direction = -1;}
  if (currentLED == 0) {direction = 1;}
}

void loop()
{
  if ((millis() - changeTime) > ledDelay) //verifica se já transcorreram ledDelay ms desde a última alteração
  {                                        
    changeLED();
    changeTime = millis();
  }
 }

