/*
Projeto: Controle de LED via Bluetooth (HC-05)

O que será usado neste projeto:
  - Arduino UNO
  - Módulo Bluetooth HC-05
  - LED + resistor
  - Divisor de tensão para RX do HC-05

Conexões (pinos sugeridos):
  - HC-05 TX -> Arduino RX (D0)
  - HC-05 RX -> Arduino TX (D1) via divisor de tensão
  - LED -> D13
*/
const int LED = 13;

void setup(){
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
  // Observação: usar D0/D1 pode atrapalhar upload; desconecte HC-05 ao gravar.
}

void loop(){
  if (Serial.available()){
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd.equalsIgnoreCase("ON")) digitalWrite(LED, HIGH);
    else if (cmd.equalsIgnoreCase("OFF")) digitalWrite(LED, LOW);
  }
}
