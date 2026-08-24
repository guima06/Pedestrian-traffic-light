//============================================
// Semáforo com botão para peões
// Autor: Duarte Guimarães
//============================================

const int LED_VERMELHO = 8;
const int LED_AMARELO = 9;
const int LED_VERDE = 10;

const int LED_PEOES_VERMELHO = 11;
const int LED_PEOES_VERDE = 12;

const int BOTAO = 2;

enum Estado
{
  VERDE,
  SEGURANCA,
  AMARELO,
  VERMELHO
};

Estado estado = VERDE;

unsigned long tempo = 0;

void setup()
{
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  pinMode(LED_PEOES_VERMELHO, OUTPUT);
  pinMode(LED_PEOES_VERDE, OUTPUT);

  pinMode(BOTAO, INPUT_PULLUP);

  digitalWrite(LED_VERDE, HIGH);

  digitalWrite(LED_PEOES_VERMELHO, HIGH);
  digitalWrite(LED_PEOES_VERDE, LOW);

  tempo = millis();
}

void loop()
{

  switch (estado)
  {

    //------------------------------
    // VERDE
    //------------------------------

    case VERDE:

      // Botão pressionado
      if (digitalRead(BOTAO) == LOW)
      {
        estado = SEGURANCA;
        tempo = millis();
      }

      // Passaram 10 segundos
      else if (millis() - tempo >= 10000)
      {
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_AMARELO, HIGH);

        estado = AMARELO;
        tempo = millis();
      }

      break;

    //------------------------------
    // Tempo de segurança
    //------------------------------

    case SEGURANCA:

      if (millis() - tempo >= 1000)
      {
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_AMARELO, HIGH);

        estado = AMARELO;
        tempo = millis();
      }

      break;

    //------------------------------
    // AMARELO
    //------------------------------

    case AMARELO:

      if (millis() - tempo >= 1000)
      {
        digitalWrite(LED_AMARELO, LOW);
        digitalWrite(LED_VERMELHO, HIGH);

        digitalWrite(LED_PEOES_VERMELHO, LOW);
        digitalWrite(LED_PEOES_VERDE, HIGH);

        estado = VERMELHO;
        tempo = millis();
      }

      break;

    //------------------------------
    // VERMELHO
    //------------------------------

    case VERMELHO:

      if (millis() - tempo >= 7000)
      {
        digitalWrite(LED_PEOES_VERDE, LOW);
        digitalWrite(LED_PEOES_VERMELHO, HIGH);

        digitalWrite(LED_VERMELHO, LOW);
        digitalWrite(LED_VERDE, HIGH);

        estado = VERDE;
        tempo = millis();
      }

      break;
  }
}
