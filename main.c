#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "bmp180/bmp180.c"
#include "uart.c"


int main(void) {
    
    serial_init();
    
	while (1) {
        init_sensor(bmp180_mode_0);
        calculate();
        printf("Temperature: %.2f C, Pressure: %.2f Pa, Altitude: %.2f m (%2.f ft),\n", (float) bmp_180.temperature / 10, (float)bmp_180.pressure, (float) bmp_180.altitude, (float) bmp_180.altitude * 3.2808);
        _delay_ms(100);
       
	}
	return 0; // never reached
}


