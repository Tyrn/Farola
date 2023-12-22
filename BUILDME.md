# An arc lamp power supply controller
## Libraries

By default, all the libraries are installed in the `~/Arduino/libraries`
directory via the
[Arduino IDE](https://github.com/Tyrn/arch-chronicle/blob/master/Usage/Arduino.md)
Library Manager, as well as manually.

- *TaskScheduler* by Anatoli Arkhipenko
- *LiquidCrystal_I2C* by Frank de Brabander
- *LCD_1602_RUS_ALL* ([fork](https://github.com/Tyrn/LCD_1602_RUS_ALL))
```
$ git clone https://github.com/Tyrn/LCD_1602_RUS_ALL ~/Arduino/libraries
```
- *EasyButton* by Evert Arias
- *STM32encoder* by bit.factory. In case of the Library Manager error, try
[this](https://forum.arduino.cc/t/dependency-stm32-is-not-available/1195285)

## Format source
- Via Clang
```
$ clang-format -i Farola.ino
```
