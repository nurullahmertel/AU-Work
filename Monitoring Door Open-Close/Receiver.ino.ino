#include <LiquidCrystal_I2C.h>

#include <Wire.h>

LiquidCrystal_I2C lcdekranim(0x27,16,2);

void setup() 
{
  Serial.begin(9600);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);

  lcdekranim.init();
  lcdekranim.backlight();
  lcdekranim.setCursor(0,0);
  lcdekranim.print("Merhaba");
  delay(3000);
  lcdekranim.clear();
}

void loop()
{
  int sensorVal1 = digitalRead(11);
  int sensorVal2 = digitalRead(12); 

  Serial.println(sensorVal1);
  Serial.println(sensorVal2);

  if (sensorVal1 == HIGH) {
    lcdekranim.setCursor(0,0);
    lcdekranim.print("0");
  } else {
    lcdekranim.setCursor(0,0);
    lcdekranim.print("1");
  }

  if (sensorVal2 == HIGH) {
    lcdekranim.setCursor(0,1);
    lcdekranim.print("0");
  } else {
    lcdekranim.setCursor(0,1);
    lcdekranim.print("1");
  }
}