//
//  uart.c
//  BMP180
//
//  Created by Atakan on 22/08/16.
//  Copyright © 2016 Atakan. All rights reserved.
//

#include <stdio.h>
#include <avr/io.h>

static void send_uart_char(unsigned char serial_data, FILE *stream) {
    if (serial_data == '\n') { // Send each byte until reached \n character
        send_uart_char('\r', stream);
    }
    
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = serial_data;
}

static FILE uart_output = FDEV_SETUP_STREAM(send_uart_char, NULL, _FDEV_SETUP_WRITE);

static void serial_init(void) {
    /*
     *
     * Initialize UART,
     * 8 bit frame, 1 Stop Bit
     * No Parity
     */
    
    UCSR0B = (1 << TXEN0);
    UBRR0L = 51;
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
    stdout = &uart_output;
}