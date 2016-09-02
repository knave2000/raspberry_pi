// Compile: gcc -Wall -o read_wiring read_wiring.c -lwiringPi
// execute: sudo ./read_wiring

#include <stdio.h>
#include <wiringPi.h>           //подключаем заголовочный файл библиотеки

#define PIN 2                   // номер PIN датчика расходомера
#define LED 8                   // номер PIN светодиода
#define COLD 596636             // показания счетчика холодной воды

static volatile int globalCounter;

void myInterrupt(void)
{
    ++globalCounter;
}

int main(void)
{
    int gotOne;
    int myCounter;

    globalCounter = myCounter = COLD;                   // начальное значение счётчика

    wiringPiSetup();                                    // инициализируем библиотеку WiringPi
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH);                            // выкл. светодиод
    pullUpDnControl (PIN, PUD_UP);                      // подтянуть по питанию
    wiringPiISR(PIN, INT_EDGE_RISING, &myInterrupt);    // вызвать функцию обработки прирывания

    printf("Started.\n");

    for (;;)
    {
        gotOne = 0;
        fflush(stdout);

        for (;;)
        {
            if (globalCounter != myCounter)
            {
                printf("Counter: %d\n", globalCounter);
                digitalWrite(LED, LOW);                 // включить светодиод
                delay(500);
                digitalWrite(LED, HIGH);                // выключить светодиод
                myCounter = globalCounter;
                ++gotOne;
            }

            if (gotOne != 0)
                break;
        }
    }

    return 0;
}
