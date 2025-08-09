/*
Projeto: Alarme com PIR + buzzer (desarme por senha no Serial)

O que será usado neste projeto:
  - Arduino UNO
  - Sensor PIR
  - Buzzer
  - LED (opcional)

Conexões (pinos sugeridos):
  - PIR -> D2
  - Buzzer -> D3
  - LED -> D4 (opcional)
*/
const int PIR = 2, BUZZER = 3, LED = 4;
const char* SENHA = "1234";
bool armado = true;

void setup(){
  pinMode(PIR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Alarme ARMADO. Digite 1234 e Enter para desarmar/armar.");
}

void loop(){
  if (Serial.available()){
    String s = Serial.readStringUntil('\n');
    s.trim();
    if (s.equals(SENHA)){
      armado = !armado;
      Serial.print("Alarme "); Serial.println(armado ? "ARMADO" : "DESARMADO");
      digitalWrite(LED, LOW);
      noTone(BUZZER);
    }
  }

  if (armado && digitalRead(PIR) == HIGH){
    digitalWrite(LED, HIGH);
    tone(BUZZER, 2000); delay(200);
    noTone(BUZZER); delay(200);
  } else {
    digitalWrite(LED, LOW);
  }
}
