/*
Projeto: Servo controlado por potenciômetro

O que será usado neste projeto:
  - Arduino UNO
  - Servo (SG90/MG90S)
  - Potenciômetro 10k
  - Fonte adequada p/ servo (se necessário)

Conexões (pinos sugeridos):
  - Potenciômetro -> A0
  - Sinal do servo -> D9
  - Alimentação do servo conforme especificação
*/
#include <Servo.h>
Servo servo;
const int PINO_POT = A0;

void setup(){
  servo.attach(9);
}

void loop(){
  int val = analogRead(PINO_POT); // 0..1023
  int ang = map(val, 0, 1023, 0, 180);
  servo.write(ang);
  delay(10);
}
