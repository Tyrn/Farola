#define _TASK_SCHEDULING_OPTIONS
// #define _TASK_TIMECRITICAL
// #define _TASK_SLEEP_ON_IDLE_RUN
#include <TaskScheduler.h>

// Display mode: 1 - I2C; 2 - 10-pin.
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>

#include <EasyButton.h>

LCD_1602_RUS lcd(0x27, 16, 2);

void tGreenCallback() { digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); }

void tOrangeCallback() { digitalWrite(PB8, !digitalRead(PB8)); }

void tCountCallback() {
  static int cnt = 1;

  lcd.setCursor(0, 0);
  lcd.print(cnt++, DEC);
}

Task tGreen(200, TASK_FOREVER, &tGreenCallback);
Task tOrange(500, TASK_FOREVER, &tOrangeCallback);
Task tCount(1000, TASK_FOREVER, &tCountCallback);

Scheduler ts;

void setup() {
  String str;
  str = ". Hexadecimal";
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PB8, OUTPUT);
  lcd.init(); // For the Blue Pill use LCD_1602_RUS_ALL fork.

  lcd.backlight();
  lcd.setCursor(0, 0);
  // lcd.print(1, DEC);
  // lcd.print(". Йа креведко!");
  // lcd.setCursor(0, 1);
  // lcd.print(15, HEX);
  // lcd.print(str);

  ts.init();
  ts.addTask(tGreen);
  tGreen.enable();
  ts.addTask(tOrange);
  tOrange.enable();
  ts.addTask(tCount);
  tCount.enable();
}

void loop() { ts.execute(); }
