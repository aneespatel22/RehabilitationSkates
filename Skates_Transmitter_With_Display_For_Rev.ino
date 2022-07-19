/*
 Pins
 CE=7
 CSN=8
 SCK=13
 MOSI=11
 MISO=12
 */

#include<SPI.h>
#include<RF24.h>
#include<nRF24L01.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>

//Joystick Pinouts
int joystickX=A0;
int joystickY=A1;
int joystickXPos;
int joystickYPos;
int xyArr[2];
int finalCount=0;
int printCount=0;
int forwardCount=0;
int reverseCount=0;
  

// Define LCD pinout
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
 
// Define I2C Address (Hexadecimal)
const int i2c_addr = 0x27;

//Create LCD object
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);
 
//NRF Address
const byte address[6]="00001";
RF24 radio(7,8);

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0); // (Column, Row)
  lcd.print("Rehabilitation");
  lcd.setCursor(0,1);
  lcd.print("Skates V.1.0");
  delay(5000);
  lcd.clear();
  for(int itr=0;itr<4;itr++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);    
  }
  lcd.backlight();

  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop()
{
  joystickXPos=analogRead(joystickX);  
  joystickYPos=analogRead(joystickY);

  xyArr[0]=joystickXPos;
  xyArr[1]=joystickYPos;
  
  radio.write(&xyArr,sizeof(xyArr));

  //Logic for Exercise count
  if(joystickYPos>921)
    forwardCount+=1;
  if(joystickYPos<102)
    reverseCount+=1;

    
  lcd.setCursor(0,0);
  lcd.print("Forward Count:");
  lcd.print(forwardCount);
  lcd.setCursor(0,1);
  lcd.print("Reverse Count:");
  lcd.print(reverseCount);

  Serial.print("X axis: ");
  Serial.print(xyArr[0]);
  Serial.print("|");
  Serial.print("Y axis: ");
  Serial.print(xyArr[1]);
  Serial.println("|");
  Serial.println(forwardCount);
  Serial.println("|");
  Serial.println(reverseCount);
}
