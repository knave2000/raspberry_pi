//GPIO-test.c
// Программа включает на 1 секунду светодиод,
// подключённый к порту P1_03
// Компиляция командой gcc -o GPIO-test GPIO-test.c -lrt -lbcm2835

#include <bcm2835.h>

#define PIN RPI_GPIO_P1_03	// для RPi ревизии v1
//#define PIN RPI_V2_GPIO_P1_03	// для RPi ревизии v2

int main()
{
	if (!bcm2835_init())	// инициализация GPIO
		return 1;	// завершение программы, если инициализация не удалась

bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);	// устанавливаем порт P1_03 на вывод
bcm2835_gpio_write(PIN, LOW);			// устанавливаем порт в 0, светодио горит
bcm2835_gpio_delay(1000);			// ждём 1000 мс (1 сек)
bcm2835_gpio_write(PIN, HIGH);			// устанавливаем порт в 1, светодиод не горит

return 0;					// выход из программы
}
