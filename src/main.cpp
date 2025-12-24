/**********************************************************************
  Filename    : TableLamp
  Description : Control led by button.
  Auther      : www.freenove.com
  Modification: 2024/06/18
**********************************************************************/
#include <Arduino.h>

#define PIN_BUZZER 13
#define PIN_BUTTON 4
#define CHN 0

void setup(){
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  ledcAttachChannel(PIN_BUZZER, 0, 10, CHN);
  ledcWriteTone(CHN, 2000);
  delay(300);
}

void alert(){
  float sinVal;
  int toneVal;

  for(int x = 0; x<360; x+=10){
    sinVal = sin(x * (PI / 180));
    toneVal = 2000 + sinVal * 500;
    ledcWriteTone(CHN, toneVal);
    delay(10);
  }
}

void loop(){
  if(digitalRead(PIN_BUTTON) == LOW){
    alert();
  } else {
    ledcWriteTone(CHN, 0);
  }
}

