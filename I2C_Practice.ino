#include<Wire.h>
#include<LiquidCrystal_I2C.h>
// Define LCD pinout
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
 
// Define I2C Address
const int i2c_addr = 0x27;
 
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);
String str="kates V.1.0";
 
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
}

void loop()
{
  
}
