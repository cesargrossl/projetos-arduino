/*
Projeto: Irrigação automática (sensor de umidade de solo + relé)

O que será usado neste projeto:
  - Arduino UNO
  - Sensor de umidade de solo (analógico)
  - Módulo Relé
  - Bomba/atuador (simular com LED se desejar)

Conexões (pinos sugeridos):
  - Sensor -> A0
  - Relé -> D8
  - Alimentação e GND conforme módulos
*/
const int PINO_SOLO = A0, PINO_RELE = 8;
int limiarSeco = 600; // ajuste conforme seu sensor

void setup(){
  pinMode(PINO_RELE, OUTPUT);
  digitalWrite(PINO_RELE, LOW);
  Serial.begin(9600);
}

void loop(){
  int leitura = analogRead(PINO_SOLO);
  Serial.print("Umidade (analog): "); Serial.println(leitura);
  if (leitura > limiarSeco){
    digitalWrite(PINO_RELE, HIGH); // liga bomba
  } else {
    digitalWrite(PINO_RELE, LOW);
  }
  delay(500);
}
