/*
Projeto: Alarme de gás com MQ-2 + buzzer + LED

O que será usado neste projeto:
  - Arduino UNO
  - Sensor MQ-2 (saída analógica)
  - Buzzer
  - LED + resistor

Conexões (pinos sugeridos):
  - MQ-2 -> A0
  - Buzzer -> D2
  - LED -> D3
*/
const int PINO_MQ2 = A0, PINO_BUZZER = 2, PINO_LED = 3;
int limiar = 350; // ajuste após calibrar em ambiente real

void setup(){
  pinMode(PINO_BUZZER, OUTPUT);
  pinMode(PINO_LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Leitura MQ-2...");
}

void loop(){
  int leitura = analogRead(PINO_MQ2);
  Serial.println(leitura);
  if (leitura > limiar){
    digitalWrite(PINO_LED, HIGH);
    tone(PINO_BUZZER, 2000);
  } else {
    digitalWrite(PINO_LED, LOW);
    noTone(PINO_BUZZER);
  }
  delay(200);
}
