//---------OLED (Organic Light emitting diode) Libraries for later display
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display = Adafruit_SSD1306();

//---Joystick Variables
int x=A0;  // Xout pin
int y=A1;  // Yout pin
int xval=0;//Value from Xout
int yval=0;//Value from Yout
int speedval=0;//Value for speed control

//----TB66 Varables
int pwmB=5; //Pin for PWMB
int BO1=6;  //Pin for BIN1 on TB66
int BO2=9;  //Pin for BIN2 on TB66
//--------------
void setup() {
  pinMode(x, INPUT);  //Recieves data from x
  pinMode(y, INPUT);  //Recieves data from y
  pinMode(BO1, OUTPUT);//Outputs data to BO1
  pinMode(BO2, OUTPUT);//Outputs data to BO2
}

void loop() {
  xval=analogRead(x);  //Find value of Xout
  yval=analogRead(y);  //Find value of Yout
  printJoyStickXY();  //Print X and Y values
  getAndSetspeed();  //convert Yout from 0 to 1023 to 0 to 255 as speed
  setDirection();  //Decide wether to turn clockwise or counter clockwise
  printDirection();  //Print direction on Serial monitor (for Debug testing)

}
