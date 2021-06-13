//Projeto 5.1 - Efeito de iluminação sequencial com LEDs (LED's se encontrando)
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // Cria um array para os pinos dos LEDs.
int ledDelay(65); //intervalo entre as alterações
int direction = 1;
int currentLED = 0;
int currentLED2 = 9;
unsigned long changeTime;

void setup()
{
  for (int x=0; x<10; x++) // define todos so pinos como saída
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
  digitalWrite(ledPin[currentLED2], HIGH);
  currentLED = currentLED + direction; //incrementa de acordo com o valor de direction
  currentLED2 = currentLED2 - direction; //faz o inverso para o LED que retorna
  //altera a direção se tivermos atingido o fim
  if (currentLED == 4) {direction = -1;}
  if (currentLED == 0) {direction = 1;}
}

void loop()
{
  if ((millis() - changeTime) > ledDelay) //verifica se já transcorreram
  {                                        //ledDelay ms desde a última alteração
    changeLED();
    changeTime = millis();
  }
}

