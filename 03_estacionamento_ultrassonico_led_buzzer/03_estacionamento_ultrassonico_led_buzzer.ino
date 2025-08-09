/*
Projeto: Assistente de estacionamento: HC-SR04 + LED + Buzzer

O que será usado neste projeto:
  - Arduino UNO
  - Sensor ultrassônico HC-SR04
  - LED + resistor
  - Buzzer passivo

Conexões (pinos sugeridos):
  - TRIG -> D8
  - ECHO -> D9
  - LED -> D3
  - Buzzer -> D4
*/
const int TRIG = 8, ECHO = 9, LED = 3, BUZZER = 4;

long medeCm() {
  digitalWrite(TRIG, LOW); delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duracao = pulseIn(ECHO, HIGH, 30000);
  if (duracao == 0) return 999;
  return duracao / 58;
}

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  Serial.println("Assistente de Estacionamento - HC-SR04");
}

void loop() {
  long d = medeCm();
  Serial.print("Distancia: "); Serial.print(d); Serial.println(" cm");

  if (d < 15) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 2000); delay(50);
    noTone(BUZZER); delay(50);
  } else if (d <= 50) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1500); delay(120);
    noTone(BUZZER); delay(d * 3);
  } else if (d <= 150) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000); delay(150);
    noTone(BUZZER); delay(d * 4);
  } else {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
    delay(300);
  }
}
