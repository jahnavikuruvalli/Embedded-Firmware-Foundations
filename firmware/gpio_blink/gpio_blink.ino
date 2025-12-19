#include <avr/io.h>

void setup() {
    // Set PB5 (Arduino pin 13) as output
    DDRB |= (1 << DDB5);
}

void loop() {
    // Set PB5 HIGH (LED ON)
    PORTB |= (1 << PORTB5);
}

