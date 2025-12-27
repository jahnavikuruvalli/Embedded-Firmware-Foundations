#include <avr/io.h>
#include <avr/interrupt.h>

void uart_init(void) {
    // Set baud rate to 9600 (16 MHz clock)
    UBRR0H = 0;
    UBRR0L = 103;

    // Enable receiver and transmitter
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    // Enable RX interrupt
    UCSR0B |= (1 << RXCIE0);

    // Set frame format: 8 data bits, 1 stop bit
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void setup() {
    // LED pin output
    DDRB |= (1 << DDB5);

    uart_init();
    sei();   // Enable global interrupts
}

ISR(USART_RX_vect) {
    char received = UDR0;

    if (received == '1') {
        PORTB |= (1 << PORTB5);   // LED ON
    } else if (received == '0') {
        PORTB &= ~(1 << PORTB5);  // LED OFF
    }
}

void loop() {
    // Main loop does nothing
}
