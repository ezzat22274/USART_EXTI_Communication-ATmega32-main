# ATmega32 Microcontroller Communication via USART and EXTI

This repository contains code for two ATmega32 microcontrollers, enabling them to communicate using USART (Universal Synchronous and Asynchronous Receiver/Transmitter) and External Interrupts (EXTI). 

## Project Overview

In this project, two ATmega32 microcontrollers are used to establish communication between them. The first microcontroller (`Uc1.c`) is configured to send specific characters ('O', 'F', 'X') to the second microcontroller in response to External Interrupts. The second microcontroller (`main.c`) receives these characters and performs corresponding actions.

## Microcontroller Configuration

### First Microcontroller (Uc1.c)

- Configured with External Interrupts:
  - External Interrupt 0: Sends 'O' character.
  - External Interrupt 1: Sends 'F' character.
  - External Interrupt 2: Sends 'X' character.
- Utilizes USART to send characters to the second microcontroller.

### Second Microcontroller (main.c)

- Configured with USART to receive characters from the first microcontroller.
- Upon receiving characters:
  - 'O' turns on one output pin and then another.
  - 'F' turns off one output pin and then another.
  - 'X' turns off both output pins.

## Drivers Used

- **DIO (Digital Input/Output) Driver:** Handles setting pin directions and values for digital I/O.
- **GIE (Global Interrupt Enable) Driver:** Enables global interrupts.
- **EXTI (External Interrupt) Driver:** Configures and handles external interrupts.
- **USART (Universal Synchronous and Asynchronous Receiver/Transmitter) Driver:** Configures USART communication.

## Usage

1. Flash the first microcontroller (`Uc1.c`) code onto one ATmega32 microcontroller.
2. Flash the second microcontroller (`main.c`) code onto another ATmega32 microcontroller.
3. Connect the Tx of UC1 with Rx of UC2.

## Note
My proteus version of simulation does not work correctly, So better try it on the hardware instead, it works fine on the hardware
