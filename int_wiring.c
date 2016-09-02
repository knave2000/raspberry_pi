// Compile: gcc -Wall -o int_wiring int_wiring.c -lwiringPi
// execute: sudo ./int_wiring

#include <stdio.h>
#include <wiringPi.h>           //подключаем заголовочный файл библиотеки

#define LED 8
#define PULSE 2

int main(void)
{
    printf("Raspberry Pi wiringPi blinking\n");

    wiringPiSetup();            // инициализируем библиотеку WiringPi
    pinMode(LED, OUTPUT);
    pinMode(PULSE, INPUT);

    for (;;)
    {
        digitalWrite(8, HIGH);  // вкл.
        delay (500);
        digitalWrite(8, LOW);   // выкл.
        delay (500);
    }

    return 0;
}
