/*
Projeto: Termômetro com LM35 no LCD 16x2 (sem I2C)

O que será usado neste projeto:
  - Arduino UNO
  - Sensor LM35
  - LCD 16x2
  - Potenciômetro 10k para contraste
  - Jumpers

Conexões (pinos sugeridos):
  - LM35 -> A0
  - LCD RS->D7, E->D8, D4->D9, D5->D10, D6->D11, D7->D12
  - Pot 10k no pino VO do LCD (contraste)
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const int PINO_LM35 = A0;

void setup(){
  lcd.begin(16,2);
  lcd.print("Termometro LM35");
  delay(1000);
  lcd.clear();
}

void loop(){
  int leitura = analogRead(PINO_LM35);
  float volts = leitura * (5.0/1023.0);
  float tempC = volts / 0.01; // 10mV por °C
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(tempC,1);
  lcd.print((char)223);
  lcd.print("C     ");
  delay(500);
}
