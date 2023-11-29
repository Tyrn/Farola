// Display mode: 1 - I2C; 2 - 10-pin.
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>

LCD_1602_RUS lcd(0x27, 16, 2);

void setup() {
  String str;
  str = ". Hexadecimal";

  lcd.init(); // For the Blue Pill use LCD_1602_RUS_ALL fork.

  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(1, DEC);
  lcd.print(". Йа креведко!");
  lcd.setCursor(0, 1);
  lcd.print(15, HEX);
  lcd.print(str);
}

void loop() {}
