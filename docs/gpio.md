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

This is the foundation for all embedded firmware work.
