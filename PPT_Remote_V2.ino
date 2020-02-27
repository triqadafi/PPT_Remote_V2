#include <Arduino.h>
#include <SoftwareSerial.h>

#define PIN_PREV 1
#define PIN_NEXT 3
#define PIN_START 4
#define PIN_BLANK 2

#define PIN_RX 99
#define PIN_TX 0

SoftwareSerial blueToothSerial(PIN_RX, PIN_TX); // RX, TX
// namba
void setup() {
    // put your setup code here, to run once:
  pinMode(PIN_PREV, INPUT_PULLUP);
  pinMode(PIN_NEXT, INPUT_PULLUP);
  pinMode(PIN_START, INPUT_PULLUP);
  pinMode(PIN_BLANK, INPUT_PULLUP);

  blueToothSerial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
  if(digitalRead(PIN_NEXT) == LOW){
    blueToothSerial.print("A"); // PAGE UP
    delay(200);
  }else if(digitalRead(PIN_PREV) == LOW){
    blueToothSerial.print("B"); // PAGE DOWN
    delay(200);
  }else if(digitalRead(PIN_START) == LOW){
    blueToothSerial.print("C"); // F5
    delay(200);
  }else if(digitalRead(PIN_BLANK) == LOW){
    blueToothSerial.print("D"); // B
    delay(200);
  }
}
