# GPIO — Bare-Metal Control (ATmega328P)

This module demonstrates direct GPIO control on the ATmega328P
without using Arduino abstractions.

## What this proves
- Understanding of DDRx and PORTx registers
- Bitwise manipulation of hardware registers
- Mapping Arduino pin 13 to PB5

## Hardware
- Arduino Uno
- Onboard LED (PB5 / Digital Pin 13)

## Key Registers
- DDRB: sets pin direction
- PORTB: controls output level

## GPIO Operations

- Set pin HIGH using bitwise OR
- Set pin LOW using bitwise AND with NOT
- Toggle pin using XOR

These operations map directly to physical pin voltage changes.

This is the foundation for all embedded firmware work.
