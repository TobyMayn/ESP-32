/**********************************************************************
  Filename    : TableLamp
  Description : Control led by button.
  Auther      : www.freenove.com
  Modification: 2024/06/18
**********************************************************************/
#include <Arduino.h>

const byte ledPins[] = {4, 2, 15};//define red, green, blue led pins
const byte chns[] = {0, 1, 2};//define the pwm channels

int red, green, blue;

void setup() {
    for (int i = 0; i < 3; i++) {
      //setup the pwm channels,1KHz,8bit
      ledcAttachChannel(ledPins[i], 500, 8, chns[i]);
    }
}

void setColor(long rgb) {
    ledcWrite(chns[0], 255 - (rgb >> 16) & 0xFF); //Common anode LED, low level to turn on the led.
    ledcWrite(chns[1], 255 - (rgb >> 8) & 0xFF);
    ledcWrite(chns[2], 255 - (rgb >> 0) & 0xFF);
}

long wheel(int pos) {
  long WheelPos = pos % 0xff;
  if (WheelPos < 85) {
    return ((255 - WheelPos * 3) << 16) | ((WheelPos * 3) << 8);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return (((255 - WheelPos * 3) << 8) | (WheelPos * 3));
  } else {
    WheelPos -= 170;
    return ((WheelPos * 3) << 16 | (255 - WheelPos * 3));
  }
}

void loop() {
  for (int i = 0; i < 256; i++){
    setColor(wheel(i));
    delay(20);
  }
}
