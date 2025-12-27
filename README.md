# 🔧 Embedded Firmware Foundations

A focused **embedded-systems firmware project** exploring **bare-metal–style development** on the **ATmega328P (Arduino Uno)**.

This repository intentionally avoids high-level Arduino abstractions and instead emphasizes **direct hardware control**, **timing correctness**, **interrupt-driven design**, and **firmware architecture**.

The goal is to build a **strong conceptual and practical foundation** in embedded systems programming — prioritizing understanding over convenience.

---

## 🎯 Project Goals

- Understand how microcontrollers work **below frameworks**
- Write firmware using **direct register manipulation**
- Learn **timing, interrupts, UART, and PWM** at the hardware level
- Develop **clean, modular firmware architecture**
- Build intuition for **real-time and resource-constrained systems**

> This project prioritizes **depth of understanding** over feature count.

---

## ⚙️ Hardware Platform

- **Microcontroller:** ATmega328P (Arduino Uno)
- **External Components:**
  - LED + resistor
  - HC-05 Bluetooth module (UART)
- **Toolchain:** Arduino toolchain (used **only for flashing**)

⚠️ Arduino is used **strictly as hardware**, not as a software framework.

---

## 🧠 Design Philosophy

- ❌ No `digitalWrite`, `analogWrite`, `delay`, or `Serial`
- ❌ No blocking, delay-based designs
- ✅ Explicit control of:
  - GPIO registers
  - hardware timers
  - interrupts
  - UART configuration
- ✅ Event-driven, non-blocking firmware
- ✅ Clear separation between **peripheral control** and **application logic**

All firmware is written with the mindset of **bare-metal systems programming**.

---

## 🧩 Implemented Modules & Learning Phases

Each concept is implemented as an **independent, self-contained firmware module**.

### 🟢 GPIO (Phase 1)
- Manual configuration of `DDRx` and `PORTx`
- Bitwise pin control (`|=`, `&=`, `^=`)
- Physical understanding of pin direction and voltage control

📁 `firmware/gpio_toggle/`

---

### 🟡 Timing & Interrupts (Phase 2)
- Software timing using loop counters (learning step)
- Hardware timers (CTC mode)
- Timer-based interrupts
- Deterministic, non-blocking timekeeping
- Correct use of `volatile`

📁 `firmware/gpio_timer_interrupt/`

---

### 🔵 UART Communication (Phase 3.1)
- Register-level UART configuration
- Baud-rate generation
- Interrupt-driven RX
- Command-based control via HC-05 Bluetooth

📁 `firmware/uart_basic/`

---

### 🟣 Cooperative Scheduler (Phase 3.2)
- Single hardware timer as system time base
- Multiple periodic tasks (LED, UART status)
- Event-driven firmware architecture
- Wrap-safe timing logic

📁 `firmware/timer_scheduler/`

---

### 🟠 PWM (Phase 3.3)
- Hardware-generated PWM using timers
- Duty-cycle control via output compare registers
- CPU-independent waveform generation
- Suitable for motors, LEDs, and actuators

📁 `firmware/pwm_hardware/`

---

## 🧠 Firmware Architecture

The firmware follows a **non-blocking, event-driven architecture**:

Hardware Interrupts
↓
Peripheral Drivers
↓
Application Logic / Scheduler
↓
Output / Communication


Key principles:
- ISRs are **short and deterministic**
- All decision-making happens in the main loop
- Time is measured using **hardware**, not software delays

This structure mirrors **real-world embedded firmware systems**.

---

## 🧪 Development Approach

- Start with **minimal hardware**
- Validate behavior **incrementally**
- Prefer **deterministic behavior** over convenience
- Avoid hidden abstractions
- Document intent and design decisions clearly

This project is designed to be:
- 🔍 Inspectable
- 📚 Educational
- 🔧 Extensible

---

## ⚠️ Disclaimer

This repository is **not a beginner Arduino tutorial** and is **not intended for production use**.

It exists to:
- deepen understanding of embedded systems
- explore low-level firmware design
- practice disciplined, hardware-oriented programming

---

## 📌 Project Status

✅ **Complete**

This project fulfills its original goals and serves as a **foundation-level embedded firmware reference**.

Future work should build **on top of this knowledge** in separate projects rather than extending this repository further.

