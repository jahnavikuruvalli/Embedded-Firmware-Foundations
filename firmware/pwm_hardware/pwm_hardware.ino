#include <avr/io.h>

void setup() {
    // Set PB1 (Arduino pin 9) as output
    DDRB |= (1 << DDB1);

    // ---- Timer1 PWM configuration ----
    // Fast PWM, 8-bit
    TCCR1A |= (1 << WGM10);
    TCCR1B |= (1 << WGM12);

    // Clear OC1A on compare match (non-inverting)
    TCCR1A |= (1 << COM1A1);

    // Prescaler = 64
    TCCR1B |= (1 << CS11) | (1 << CS10);

    // Duty cycle = 50%
    OCR1A = 128;
}

void loop() {
    // Nothing here — hardware generates PWM
}

