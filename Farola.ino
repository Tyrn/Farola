#define _TASK_SCHEDULING_OPTIONS
// #define _TASK_TIMECRITICAL
// #define _TASK_SLEEP_ON_IDLE_RUN
#include <TaskScheduler.h>

// Display mode: 1 - I2C; 2 - 10-pin.
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>

#include <EasyButton.h>
#include <STM32encoder.h>

LCD_1602_RUS lcd(0x27, 16, 2);

int32_t prevPos = 0;
int16_t myVar = 64;
int16_t prevmyVar = myVar;

void tGreenCallback() { digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); }

void tOrange1Callback() { digitalWrite(PB8, !digitalRead(PB8)); }

void tOrange2Callback() { digitalWrite(PB9, !digitalRead(PB9)); }

int unilen(const char *s) {
  int len = 0;
  while (*s)
    len += (*s++ & 0xc0) != 0x80;
  return len;
}

void tCountCallback() {
  static int cnt = 1;
  static char label[] = "Счёт: ";
  static int len0 = unilen(label);

  lcd.setCursor(16 - len0 - String(cnt).length(), 1);
  lcd.print(label);
  lcd.print(cnt++, DEC);
}

void clearLCDLine(int line) {
  lcd.setCursor(0, line);
  for (int n = 0; n < 16; n++) {
    lcd.print(" ");
  }
}

void tEncoderCallback() {
  clearLCDLine(0);
  lcd.setCursor(0, 0);
  lcd.print(prevPos, DEC);
}

Task tEncoder(100, TASK_FOREVER, &tEncoderCallback);
Task tGreen(200, TASK_FOREVER, &tGreenCallback);
Task tOrange1(500, TASK_FOREVER, &tOrange1Callback);
Task tOrange2(700, TASK_FOREVER, &tOrange2Callback);
Task tCount(1000, TASK_FOREVER, &tCountCallback);

Scheduler ts;
STM32encoder enc(TIM2, 0x07);

void setup() {
  String str;
  str = ". Hexadecimal";

  // Serial.begin(115200);
  enc.bind(&myVar);
  enc.dynamic(20, 30, false);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PB8, OUTPUT);
  pinMode(PB9, OUTPUT);
  lcd.init(); // For the Blue Pill use LCD_1602_RUS_ALL fork.

  lcd.backlight();
  lcd.setCursor(0, 0);
  // lcd.print(1, DEC);
  // lcd.print(". Йа креведко!");
  // lcd.setCursor(0, 1);
  // lcd.print(15, HEX);
  // lcd.print(str);

  ts.init();
  ts.addTask(tEncoder);
  tEncoder.enable();
  ts.addTask(tGreen);
  tGreen.enable();
  ts.addTask(tOrange1);
  tOrange1.enable();
  ts.addTask(tOrange2);
  tOrange2.enable();
  ts.addTask(tCount);
  tCount.enable();
}

void loop() {
  ts.execute();

  if (enc.isUpdated()) {
    // Serial.printf("pos:%ld\n", enc.pos());
    // lcd.setCursor(0, 0);
    // lcd.printf("pos:%ld", (long)enc.pos());
    // lcd.print(enc.pos(), DEC);
    int32_t pos = enc.pos();
    // Serial.printf(
    //     "pos:%5ld myVar:%5d speed:%2d pos delta:%2ld myVar delta:%3ld\n"
    //     , pos
    //     , myVar
    //     , enc.speed()
    //     , pos - prevPos
    //     , myVar - prevmyVar
    // );
    prevPos = pos;
    prevmyVar = myVar;
  }
}
