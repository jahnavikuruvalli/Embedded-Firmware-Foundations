# Embedded Firmware Foundations

A focused embedded-systems project that explores **bare-metal–style firmware development** on the **ATmega328P (Arduino Uno)**.

This repository is intentionally designed to avoid high-level Arduino abstractions and instead emphasizes **direct hardware control**, **timing correctness**, and **firmware architecture**.

The goal is to build a strong conceptual and practical foundation in embedded systems programming.

---

## 🎯 Project Goals

- Understand how microcontrollers work **below frameworks**
- Write firmware using **direct register manipulation**
- Learn timing, interrupts, and PWM at the hardware level
- Develop clean, modular firmware architecture
- Build intuition for **real-time and resource-constrained systems**

This project prioritizes **depth of understanding** over feature count.

---

## ⚙️ Hardware Platform

- **Microcontroller:** ATmega328P (Arduino Uno)
- **Components:**
  - LED + resistor
  - HC-05 Bluetooth module (UART)
- **Toolchain:** Arduino toolchain (used only for flashing, not abstractions)

Arduino is used **only as hardware**, not as a software framework.

---

## 🧠 Design Philosophy

- No `digitalWrite`, `analogWrite`, or high-level Arduino helpers
- No blocking `delay()`-based designs
- Explicit control of:
  - GPIO registers
  - timers
  - interrupts
  - UART configuration
- Clear separation between **hardware drivers** and **application logic**

All firmware is written with the mindset of **bare-metal systems programming**.

---

## 🧩 Implemented / Planned Modules

### GPIO
- Manual configuration of DDRx and PORTx registers
- Bitwise pin control
- Pin abstraction without runtime overhead

### Timers
- Hardware timer configuration
- Periodic task scheduling
- Non-blocking timing mechanisms

### Interrupts
- Timer-based interrupts
- Interrupt Service Routines (ISR)
- Safe shared-state handling using `volatile`

### PWM
- Timer-based PWM generation
- Duty-cycle control
- Suitable for motor or actuator control

### UART
- Register-level UART setup
- Serial communication over HC-05 Bluetooth
- Command-based interaction with firmware

---

## 🧠 Firmware Architecture

The firmware follows a **non-blocking, state-machine–driven design**:

Hardware Interrupts

↓

Peripheral Drivers

↓

Application State Machine

↓

Output / Communication

This structure mirrors real-world embedded firmware systems.

---

## 🧪 Development Approach

- Start with minimal hardware (LED, UART)
- Validate behavior incrementally
- Prefer deterministic behavior over convenience
- Document design decisions clearly

This project is intended to be **educational, inspectable, and extensible**.

---

## ⚠️ Disclaimer

This repository is **not a beginner Arduino tutorial** and is **not intended for production use**.

It exists to:
- deepen understanding of embedded systems
- explore low-level firmware design
- practice disciplined hardware-oriented programming
