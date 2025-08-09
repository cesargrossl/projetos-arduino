/*
Projeto: Contador 0–9 em display de 7 segmentos (cátodo comum)

O que será usado neste projeto:
  - Arduino UNO
  - Display de 7 segmentos (cátodo comum)
  - Resistores para segmentos

Conexões (pinos sugeridos):
  - Segmentos a,b,c,d,e,f,g -> D2,D3,D4,D5,D6,D7,D8 (nesta ordem)
  - Cátodo comum -> GND via resistor se necessário (dependendo do módulo)
*/
const int pinosSeg[7] = {2,3,4,5,6,7,8}; // a..g
// Máscaras (bit0=a ... bit6=g) para cátodo comum (HIGH acende)
const unsigned char digitos[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

void setup(){
  for (int i=0;i<7;i++) pinMode(pinosSeg[i], OUTPUT);
}

void mostraDigito(int d){
  unsigned char m = digitos[d];
  for (int i=0;i<7;i++){
    bool acende = (m >> i) & 0x01;
    digitalWrite(pinosSeg[i], acende ? HIGH : LOW);
  }
}

void loop(){
  for (int d=0; d<=9; d++){
    mostraDigito(d);
    delay(700);
  }
}
