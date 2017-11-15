#include "SSD1306.h" // thu vien de hien thi OLED
#include <Wire.h>
// IoT Wifi Uno-----Cam bien mua
//      ADC---------------A0
//      3.3V--------------VCC
//      GND---------------GND
int nRainIn = 0;          // khai bao chan ADC
int nRainVal;             // bien de doc gia tri ADC
SSD1306  display(0x3c, 4, 5);

char temperatureCString[10];

void setup() {
  Serial.begin(9600);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_24); // size chu
  pinMode(2, INPUT_PULLUP);
}
void loop()
{
  nRainVal = analogRead(nRainIn);
  Serial.print("\t Moisture Level: ");
  Serial.println(nRainVal);

  display.clear();
  display.drawString(0, 20, String(nRainVal)); // hien thi gia tri ADC
  display.drawString(10, 0, "UiTiOt");
  if (nRainVal < 320)
  {
    display.drawString(40, 20, "Duoc roi!");
    display.drawString(00, 40, "Chay mach!");
  }
  else if (nRainVal > 320 && nRainVal < 650)
    display.drawString(40, 20, "Co nuoc");
  /*if(nRainVal < 320)
  {
    display.drawString(40, 20, ":STOP");
    display.drawString(00, 40, "the nay thoi");
  }
  else
  {
    display.drawString(40, 20, ":Xuong");
    display.drawString(0, 40, "them ti nua!");
  }*/
  display.display();
  delay(60);
}
