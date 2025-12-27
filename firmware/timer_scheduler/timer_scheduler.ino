#include <avr/io.h>
#include <avr/interrupt.h>

// ---- Global time base ----
volatile uint16_t system_ticks = 0;

// ---- Task timers ----
uint16_t led_timer = 0;
uint16_t uart_timer = 0;

void uart_send_char(char c) {
    while (!(UCSR0A & (1 << UDRE0)));  // Wait until buffer empty
    UDR0 = c;
}

void uart_send_string(const char *s) {
    while (*s) {
        uart_send_char(*s++);
    }
}

void uart_init(void) {
    UBRR0L = 103;  // 9600 baud @ 16 MHz
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void timer1_init(void) {
    TCCR1B |= (1 << WGM12);       // CTC mode
    OCR1A = 249;                  // 1 ms tick
    TIMSK1 |= (1 << OCIE1A);      // Enable compare interrupt
    TCCR1B |= (1 << CS11) | (1 << CS10);  // Prescaler 64
}

void setup() {
    DDRB |= (1 << DDB5);   // LED pin output

    uart_init();
    timer1_init();

    sei();  // Enable global interrupts
}

// ---- Timer ISR: system heartbeat ----
ISR(TIMER1_COMPA_vect) {
    system_ticks++;
}

// ---- UART RX ISR ----
ISR(USART_RX_vect) {
    char c = UDR0;

    if (c == '1') {
        PORTB |= (1 << PORTB5);
    } else if (c == '0') {
        PORTB &= ~(1 << PORTB5);
    }
}

void loop() {
    // --- LED task (500 ms) ---
    if ((system_ticks - led_timer) >= 500) {
        PORTB ^= (1 << PORTB5);
        led_timer = system_ticks;
    }

    // --- UART status task (1000 ms) ---
    if ((system_ticks - uart_timer) >= 1000) {
        uart_send_string("System alive\r\n");
        uart_timer = system_ticks;
    }
}

