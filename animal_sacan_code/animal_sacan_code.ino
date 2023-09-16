/*
  #Título: ANIMAL SCAN

  #Autoras:
    Vanessa Santos do Nascimento - 2019128@aluno.diocesanocaruaru.g12.br
    Julia Gabriela Campos de Lima Medeiros - 20230116@aluno.diocesanocaruaru.g12.br

  #Orientador: Prof. Diógenes Souza - diogenes@diocesanocaruaru.g12.br

  #Repositório do projeto no GitHub: https://github.com/Diocesano/animal_scan

  #Descrição:

    O objetivo principal de nosso trabalho é desenvolver o protótipo de um sistema,
    a ser implantado em automóveis, para detectar a presença de animais abrigados
    abaixo do veículo ou dentro da área em que fica localizado o motor. O projeto
    pretende evitar que animais sejam levados para locais distantes onde possam se
    perder, ou que sejam feridos ou mortos através do funcionamento e deslocamento
    do carro. No projeto, quando o sensor PIR detecta movimento, envia o sinal para
    o pino digital 7 do Arduino, que está no modo INPUT. O Arduino, por sua vez,
    envia sinais para o buzzer ativo 5v e o LED difuso 5mm, através das portas
    digitais 8 e 9, respectivamente. É importante destacar que não estamos usando
    resistor com o LED pois estamos controlando a tensão através do pino 9~PWM.

  #Componentes:
    ->1 placa Arduino Uno R3, utilizando o microcontrolador Atmel Atmega328p;
    ->1 sensor de movimento PIR;
    ->1 buzzer ativo 5v; e
    ->1 LED difuso vermelho 10mm.


  #Conexões:

                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |                                     |
         |                           A5/SCL[ ] |
         |                           A4/SDA[ ] |
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                        13[ ] |
         | [ ]IOREF                 MISO/12[ ] |
         | [ ]RST                       ~11[ ] |
         | [ ]3V3    +---+              ~10[ ] |
         | [ ]5v    -| A |-              ~9[C] |
         | [ ]GND   -| R |-               8[B] |
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[A] |
         |          -| I |-              ~6[ ] |
         | [ ]A0    -| N |-              ~5[ ] |
         | [ ]A1    -| O |-               4[ ] |
         | [ ]A2     +---+               ~3[ ] |
         | [ ]A3                          2[ ] |
         | [ ]A4                       TX>1[ ] |
         | [ ]A5                       RX<0[ ] |
         |                                     |
         |  UNO_R3                 ____________/
          \_______________________/

    #PINOS:
      A (7)- SENSOR DE MOVIMENTO PIR
      B (8)- BUZZER ATIVO 5V
      C (9)- LED DIFUSO VERMELHO 10MM
  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
  LICENÇA - Copyright 2023 Vanessa Santos, Julia Gabriela e Diógenes Souza
  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/gpl-3.0.txt>.
    -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
    Este programa é um software livre; você pode redistribuí-lo e/ou
    modificá-lo dentro dos termos da Licença Pública Geral GNU como
    publicada pela Fundação do Software Livre (FSF); na versão 3 da
    Licença.
    Este programa é distribuído na esperança de que possa ser útil,
    mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
    a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
    Licença Pública Geral GNU para maiores detalhes.
    Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
    com este programa. Se não, veja <https://www.gnu.org/licenses/gpl-3.0.txt>.

  ---------------------------------------------------------------------------
*/

byte PIR = 7;
byte BUZZER = 8;
byte LED = 9;
byte movimento;

void setup() {
  pinMode(PIR, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  movimento = digitalRead(PIR);
  if ( movimento == 1) {
    alerta();
  }
}

void alerta() {
  analogWrite(LED, 100);
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
  delay(100);
  digitalWrite(BUZZER, HIGH);
  delay(400);
  digitalWrite(BUZZER, LOW);
  delay(100);
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
  delay(100);
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
  delay(100);
  digitalWrite(BUZZER, HIGH);
  delay(400);
  digitalWrite(BUZZER, LOW);
  delay(100);
  digitalWrite(BUZZER, HIGH);
  delay(400);
  digitalWrite(BUZZER, LOW);
  analogWrite(LED, 0);
  delay(1000);
}
