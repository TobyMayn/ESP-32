/**********************************************************************
  Filename    : TableLamp
  Description : Control led by button.
  Auther      : www.freenove.com
  Modification: 2024/06/18
**********************************************************************/
#include <Arduino.h>
#define PIN_LED 2 //define the led pin
#define CHN 0     //define the pwm channel
#define FRQ 1000  //define the pwm frequency
#define PWM_BIT 8 //define the pwm precision

void setup(){
  //attach led pin to pwm channel
  ledcAttachChannel(PIN_LED, FRQ, PWM_BIT, CHN);
} 

void loop(){
  for (int i = 0; i < 255; i++){
    ledcWrite(PIN_LED, i);
    delay(10);
  }
  for (int i = 255; i > -1; i--){
    ledcWrite(PIN_LED, i);
    delay(10);
  }
}