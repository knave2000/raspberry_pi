//button2.c
// Программа включает светодиод
// при обнаружении нажатой кнопки на порту P1_11.
// Используется подтяжка к питанию.
// Светодиод подключён к порту P1_03
// Компиляция командой: gcc -o button2 button2.c -lrt -lbcm2835
// Запуск: sudo ./button2

#include <stdio.h>
#include <bcm2835.h>

//#define PIN RPI_GPIO_P1_03	    // для RPi ревизии v1
#define PIN RPI_V2_GPIO_P1_03	    // определяем порт для подключения светодиода
#define PIN_IN RPI_V2_GPIO_P1_11    // определяем порт для чтения

int main()
{
	if (!bcm2835_init())    // инициализация GPIO
		return 1;           // аварийное завершение программы, если инициализация не удалась
                            // выдаёт на выходе код 1

    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);	    // устанавливаем порт P1_03 на вывод
    bcm2835_gpio_fsel(PIN_IN, BCM2835_GPIO_FSEL_INPT);  // устанавливаем порт P1_11 на ввод
    bcm2835_gpio_set_pud(PIN_IN, 2);                    // включаем подтяжку порта к +3.3. в

    printf("Ждём нажатия на кнопку!\n");

    while(1) {                                  // повторяем все действия, заключённые в скобках
                                                // пока не будет нажата кнопка.
        if(!bcm2835_gpio_lev(PIN_IN))            // если обнаружено нажатие на кнопку
                bcm2835_gpio_write(PIN, LOW);	// устанавливаем порт в 0, светодиод горит
        else                                    // иначе
            bcm2835_gpio_write(PIN, HIGH);      // устанавливаем порт в 1, светодиод не горит
    }
    return (bcm2835_close());                   // нормальный выход из программы
					                            // выдаёт на выходе код 0
}
