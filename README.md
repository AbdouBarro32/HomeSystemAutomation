# Smart Home Automation System

A comprehensive embedded systems project implementing a smart home controller using Arduino Due (Atmel SAM3X8E ARM Cortex-M3).

## Project Overview
This smart home automation system provides real-time monitoring and control of various home functions through an integrated microcontroller platform. The system features temperature monitoring, automated shade control, and a user-friendly interface.

## Key Features
- **Real-time Clock System**
  - Calendar functionality with date/time display (DD/MM/YYYY | HH:mm:ss)
  - User-configurable settings via keypad
  - Fast-mode simulation for testing (30 minutes compressed to 1 second)

- **Temperature Monitoring**
  - 7-day temperature recording with minute-by-minute logging
  - Efficient memory management using linked lists
  - Temperature alarm system with configurable thresholds
  - Statistical analysis (min/max/average) with timestamps

- **Automated Shade Control**
  - Light-sensitive motorized shading system
  - Servo-controlled window shade positioning
  - Automatic adjustment based on sunlight intensity
  - 16-hour operational period with 8-hour rest cycle

- **User Interface**
  - LCD display for system status and configuration
  - 12-key membrane keypad for user input
  - Real-time system status updates
  - Configurable alarm settings

## Technical Implementation
- Microcontroller: Atmel SAM3X8E (Arduino Due)
- Architecture: ARM Cortex-M3 RISC
- Clock Speed: 84 MHz
- Memory Management: Dynamic linked list implementation
- Peripheral Integration:
  - PWM-controlled servo motor
  - Single-wire temperature sensor
  - LCD display with RA6963 controller
  - 12-key membrane keypad

## Development Highlights
- Implemented Harvard Architecture for efficient instruction/data handling
- Used SysTick timer for precise timing control
- Integrated multiple peripheral controllers (PIO, PMC, PWM)
- Developed efficient memory management system
- Created robust interrupt handling mechanisms

## Documentation
Full technical documentation includes:
- Functional block diagrams
- Hardware driver implementations
- System architecture details
- Component integration specifications
