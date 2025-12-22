#include <avr/io.h>

void setup() {
    // Set PB5 (Arduino pin 13) as output
    DDRB |= (1 << DDB5);
}

void loop() {
    PORTB ^= (1 << PORTB5);
    for (volatile long i = 0; i < 100000; i++);
}




