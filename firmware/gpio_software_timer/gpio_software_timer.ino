#include <avr/io.h>

void setup() {
    // Configure PB5 (Arduino pin 13) as output
    DDRB |= (1 << DDB5);
}

void loop() {
    static unsigned long counter = 0;

    counter++;

    if (counter >= 500000UL) {
        PORTB ^= (1 << PORTB5);  // Toggle LED
        counter = 0;
    }
}

