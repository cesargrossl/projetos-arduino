# 10 Projetos Arduino UNO — PT-BR

Este repositório contém **10 projetos práticos** para Arduino UNO, cada um em sua própria pasta, com código fonte em português e comentários explicativos.  
Todos os sketches possuem cabeçalho descrevendo **o que será usado** e **as conexões sugeridas**.

## Lista de Projetos
1. **Casa inteligente: LDR + Relé + Botão** — acende luz automaticamente no escuro, com opção de controle manual.
2. **Semáforo com botão de pedestre** — simulação de semáforo para carros e pedestres.
3. **Assistente de estacionamento: HC-SR04 + LED + Buzzer** — avisa distância com sinais sonoros.
4. **Alarme com PIR + buzzer (senha no Serial)** — dispara alarme ao detectar movimento, com desarme via senha.
5. **Termômetro com LM35 no LCD 16x2** — mede temperatura e exibe em LCD.
6. **Servo controlado por potenciômetro** — mapeia posição do potenciômetro para o ângulo do servo.
7. **Controle de LED via Bluetooth (HC-05)** — liga/desliga LED por comando Bluetooth.
8. **Irrigação automática (umidade do solo + relé)** — aciona bomba de água quando o solo está seco.
9. **Contador 0–9 em display de 7 segmentos** — exibe contagem de 0 a 9.
10. **Alarme de gás (MQ-2 + buzzer + LED)** — dispara alarme quando detecta concentração de gás.

## Bibliotecas Utilizadas
Todos os projetos utilizam apenas bibliotecas padrão da IDE Arduino:
- `LiquidCrystal` (projeto 05)
- `Servo` (projeto 06)

## Como Usar
1. Escolha o projeto desejado e abra o arquivo `.ino` na IDE Arduino.
2. Monte o circuito conforme descrito no cabeçalho do código.
3. Carregue o sketch no Arduino UNO.
4. Teste e ajuste valores conforme seu hardware (pinos, limiares, tempos).

## Aviso de Uso Educacional
Este conjunto de projetos foi desenvolvido com o objetivo de **uso educacional**,  
destinado ao aprendizado de programação e prototipagem com **Arduino UNO**.

Pode ser utilizado em sala de aula, cursos, oficinas ou estudos individuais,  
servindo como base para compreender o funcionamento de sensores, atuadores e lógica de controle.

> **Atenção:** Não utilizar diretamente em aplicações críticas ou industriais sem as devidas adaptações e testes.

---
💡 Sinta-se à vontade para modificar e expandir os exemplos para criar seus próprios projetos!
