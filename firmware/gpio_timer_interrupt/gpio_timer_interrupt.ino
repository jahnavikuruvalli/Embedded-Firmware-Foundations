#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t tick_count = 0;

void setup() {
    // Configure PB5 (Arduino pin 13) as output
    DDRB |= (1 << DDB5);

    // ---- Timer1 configuration ----
    // Set Timer1 to CTC mode
    TCCR1B |= (1 << WGM12);

    // Set compare value for 1 ms interrupt
    OCR1A = 249;

    // Enable Timer1 compare interrupt
    TIMSK1 |= (1 << OCIE1A);

    // Start Timer1 with prescaler 64
    TCCR1B |= (1 << CS11) | (1 << CS10);

    // Enable global interrupts
    sei();
}

ISR(TIMER1_COMPA_vect) {
    tick_count++;
}

void loop() {
    if (tick_count >= 500) {   // ~500 ms
        PORTB ^= (1 << PORTB5);  // Toggle LED
        tick_count = 0;
    }
}

