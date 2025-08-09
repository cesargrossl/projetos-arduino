/*
Projeto: Semáforo com botão de pedestre

O que será usado neste projeto:
  - Arduino UNO
  - 5 LEDs (carros: verde/amarelo/vermelho; pedestres: vermelho/verde)
  - Resistores para LEDs
  - Botão de pedestre

Conexões (pinos sugeridos):
  - Carros: Verde->D2, Amarelo->D3, Vermelho->D4
  - Pedestres: Vermelho->D5, Verde->D6
  - Botão -> D7 (INPUT_PULLUP)
*/
const int CAR_VERDE = 2, CAR_AMARELO = 3, CAR_VERMELHO = 4;
const int PED_VERMELHO = 5, PED_VERDE = 6;
const int PINO_BOTAO = 7;

void apagaTudo() {
  digitalWrite(CAR_VERDE, LOW);
  digitalWrite(CAR_AMARELO, LOW);
  digitalWrite(CAR_VERMELHO, LOW);
  digitalWrite(PED_VERMELHO, LOW);
  digitalWrite(PED_VERDE, LOW);
}

void setup() {
  pinMode(CAR_VERDE, OUTPUT);
  pinMode(CAR_AMARELO, OUTPUT);
  pinMode(CAR_VERMELHO, OUTPUT);
  pinMode(PED_VERMELHO, OUTPUT);
  pinMode(PED_VERDE, OUTPUT);
  pinMode(PINO_BOTAO, INPUT_PULLUP);
  apagaTudo();
  digitalWrite(CAR_VERDE, HIGH);
  digitalWrite(PED_VERMELHO, HIGH);
}

void atendePedestre() {
  digitalWrite(CAR_VERDE, LOW);
  digitalWrite(CAR_AMARELO, HIGH); delay(2000);
  digitalWrite(CAR_AMARELO, LOW);
  digitalWrite(CAR_VERMELHO, HIGH); delay(1000);

  digitalWrite(PED_VERMELHO, LOW);
  digitalWrite(PED_VERDE, HIGH); delay(5000);

  digitalWrite(PED_VERDE, LOW);
  digitalWrite(PED_VERMELHO, HIGH); delay(1000);

  digitalWrite(CAR_VERMELHO, LOW);
  digitalWrite(CAR_VERDE, HIGH);
}

void loop() {
  if (digitalRead(PINO_BOTAO) == LOW) {
    atendePedestre();
  }
  delay(50);
}
