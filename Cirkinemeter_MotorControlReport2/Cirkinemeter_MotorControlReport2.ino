//---------OLED info
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display = Adafruit_SSD1306();
//--------------
int x=A0;
int y=A1;
int xval=0;
int yval=0;
int speedval=0;
//--------------
int pwmB=5;
int AO1=6;
int AO2=9;
//--------------
void setup() {
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(AO1, OUTPUT);
  pinMode(AO2, OUTPUT);// put your setup code here, to run once:
}

void loop() {
  xval=analogRead(x);
  yval=analogRead(y);
  printJoyStickXY();
  getAndSetspeed();
  setDirection();
  printDirection();

}
