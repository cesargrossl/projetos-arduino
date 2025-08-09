/*
Projeto: Casa inteligente: LDR + Relé + Botão (override)

O que será usado neste projeto:
  - Arduino UNO
  - LDR + resistor (divisor de tensão)
  - Módulo Relé (ou LED para simulação)
  - Botão (push button)

Conexões (pinos sugeridos):
  - LDR -> A0 (com divisor de tensão)
  - Relé/LED -> D8
  - Botão -> D7 (INPUT_PULLUP)
  - GND e 5V conforme módulos
*/
const int PINO_LDR = A0;
const int PINO_RELE = 8;
const int PINO_BOTAO = 7;

bool modoManual = false;
bool luzLigada = false;
unsigned long ultimoDebounce = 0;
const unsigned long debounceMs = 200;

void setup() {
  pinMode(PINO_RELE, OUTPUT);
  pinMode(PINO_BOTAO, INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(PINO_RELE, LOW);
  Serial.println("Casa Inteligente - LDR + Rele + Botao");
}

void loop() {
  if (digitalRead(PINO_BOTAO) == LOW && (millis() - ultimoDebounce) > debounceMs) {
    modoManual = !modoManual;
    ultimoDebounce = millis();
  }

  int leituraLdr = analogRead(PINO_LDR);
  if (!modoManual) {
    int limiar = 600; // ajuste conforme seu divisor/sensor
    luzLigada = (leituraLdr < limiar); // acende se escuro
  }
  digitalWrite(PINO_RELE, luzLigada ? HIGH : LOW);
  delay(100);
}
