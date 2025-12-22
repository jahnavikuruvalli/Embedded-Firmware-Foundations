#include <avr/io.h>

void setup() {
    // Configure PB5 (Arduino pin 13) as out/Users/jahnavikaranam/embedded-firmware-foundations/firmwareput
    DDRB |= (1 << DDB5);
}

void loop() {
    // Toggle LED as fast as possible (no timing control)
    PORTB ^= (1 << PORTB5);
}

