// Projeto 11 - Alarme com sonorizador piezo

float sinVal;
int toneVal;
void setup()
{
  pinMode(8, OUTPUT);
}

void loop()
{
  for (int x=0; x<180; x++)
  {
    // converte graus para radianos, e depois obtém o valor do seno
    sinVal = (sin(x*(3,1416/180)));
    // gera uma frequência a partir do valor do seno
    toneVal = 2000+(int(sinVal*1000));
    tone(8, toneVal);
    delay(2);
  }
}

