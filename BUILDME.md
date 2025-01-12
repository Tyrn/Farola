# An arc lamp power supply controller

## Libraries

By default, all the libraries are installed in the `~/Arduino/libraries`
directory via the
[Arduino IDE](https://github.com/Tyrn/arch-chronicle/blob/master/Usage/Arduino.md)
Library Manager, as well as manually.

- _TaskScheduler_ by Anatoli Arkhipenko
- _LiquidCrystal_I2C_ by Frank de Brabander
- _LCD_1602_RUS_ALL_ ([fork](https://github.com/Tyrn/LCD_1602_RUS_ALL))

```
git clone https://github.com/Tyrn/LCD_1602_RUS_ALL ~/Arduino/libraries/LCD_1602_RUS_ALL
```

- _EasyButton_ by Evert Arias
- _STM32encoder_ by bit.factory. In case of the Library Manager error, try
  [this](https://forum.arduino.cc/t/dependency-stm32-is-not-available/1195285)

## Format source

- Via Clang

```
$ clang-format -i Farola.ino
```
