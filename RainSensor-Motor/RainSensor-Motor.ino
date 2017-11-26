#include <Wire.h>
// IoT Wifi Uno-----Cam bien mua
//      ADC---A0      3.3V---VCC     GND---GND
int nRainIn = 0;          // khai bao chan ADC
int nRainVal;             // bien de doc gia tri ADC
int motor = 5;  // GPIO5
int flag = 0;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
}
void loop() {
  nRainVal = analogRead(nRainIn);
  Serial.print("\t Moisture Level: ");
  Serial.println(nRainVal);
  digitalWrite(motor, HIGH);
  if (nRainVal < 450) {
    if (flag == 0) {
      flag = 1;
      digitalWrite(motor, LOW);
      Serial.println("**************************************");
      delay(1500);
    }
  }
  else
  {
    flag = 0;
    digitalWrite(motor, HIGH);
  }
  delay(500);
}
