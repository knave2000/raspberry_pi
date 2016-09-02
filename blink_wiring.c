// Compile: gcc -Wall -o blink_wiring blink_wiring.c -lwiringPi
// execute: sudo ./blink_wiring

#include <wiringPi.h> //подключаем заголовочный файл библиотеки
int main (void)
{
  wiringPiSetup () ; //инициализируем библиотеку
  pinMode (8, OUTPUT) ;
  for (;;)
  {
    digitalWrite (8, HIGH) ; delay (500) ;
    digitalWrite (8,  LOW) ; delay (500) ;
  }
  return 0 ;
}
