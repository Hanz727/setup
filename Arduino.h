#ifndef Arduino_h
#define Arduino_h

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#ifdef __cplusplus
extern "C"{
#endif

void yield(void);

#define _BV(x) ( 1 << (x))

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

// ATmega2560 register definitions (Arduino Mega)
// Timer/Counter 1 Control Register A
static int TCCR1A; 
#define WGM10 0
#define WGM11 1
#define COM1C0 2
#define COM1C1 3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

// Timer/Counter 1 Control Register B
static int TCCR1B;
#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7

// Timer/Counter 1 Control Register C
static int TCCR1C;
#define FOC1C 5
#define FOC1B 6
#define FOC1A 7

// Timer/Counter 1
static int TCNT1; 
static int TCNT1L; 
static int TCNT1H; 

// Output Compare Register 1A
static int OCR1A;
static int OCR1AL;
static int OCR1AH;

// Output Compare Register 3C
static int OCR3C;
static int OCR3CL;
static int OCR3CH;

// Output Compare Register 3A
static int OCR3A;
static int OCR3AL;
static int OCR3AH;

// Output Compare Register 4A
static int OCR4A;
static int OCR4AL;
static int OCR4AH;

// Output Compare Register 1B
static int OCR1B; 
static int OCR1BL; 
static int OCR1BH; 

// Output Compare Register 1C
static int OCR1C; 
static int OCR1CL; 
static int OCR1CH; 

// Input Capture Register 1
static int ICR1; 
static int ICR1L; 
static int ICR1H; 

// Timer/Counter Interrupt Mask Register
static int TIMSK1; 
#define TOIE1 0
#define OCIE1A 1
#define OCIE1B 2
#define OCIE1C 3
#define ICIE1 5

// Timer/Counter 3 Control Register A
static int TCCR3A;
#define WGM30 0
#define WGM31 1
#define COM3C0 2
#define COM3C1 3
#define COM3B0 4
#define COM3B1 5
#define COM3A0 6
#define COM3A1 7

// Timer/Counter 3 Control Register B
static int TCCR3B;
#define CS30 0
#define CS31 1
#define CS32 2
#define WGM32 3
#define WGM33 4
#define ICES3 6
#define ICNC3 7

// Timer/Counter 3 Control Register C
static int TCCR3C;
#define FOC3C 5
#define FOC3B 6
#define FOC3A 7

// Timer/Counter 4 Control Register A
static int TCCR4A;
#define WGM40 0
#define WGM41 1
#define COM4C0 2
#define COM4C1 3
#define COM4B0 4
#define COM4B1 5
#define COM4A0 6
#define COM4A1 7

// Timer/Counter 4 Control Register B
static int TCCR4B;
#define CS40 0
#define CS41 1
#define CS42 2
#define WGM42 3
#define WGM43 4
#define ICES4 6
#define ICNC4 7

// Timer/Counter 5 Control Register A
static int TCCR5A;
#define WGM50 0
#define WGM51 1
#define COM5C0 2
#define COM5C1 3
#define COM5B0 4
#define COM5B1 5
#define COM5A0 6
#define COM5A1 7

// Timer/Counter 5 Control Register B
static int TCCR5B;
#define CS50 0
#define CS51 1
#define CS52 2
#define WGM52 3
#define WGM53 4
#define ICES5 6
#define ICNC5 7

// USART0 Control and Status Register A
static int UCSR0A;
#define MPCM0 0
#define U2X0 1
#define UPE0 2
#define DOR0 3
#define FE0 4
#define UDRE0 5
#define TXC0 6
#define RXC0 7

// USART0 Control and Status Register B
static int UCSR0B;
#define TXB80 0
#define RXB80 1
#define UCSZ02 2
#define TXEN0 3
#define RXEN0 4
#define UDRIE0 5
#define TXCIE0 6
#define RXCIE0 7

// USART0 Baud Rate Register
static int UBR;
static int UBRR0L;
static int UBRR0H;

// USART0 I/O Data Register
static int UDR0;

// Pin manipulation macros
#define digitalPinToPort(P) ( pgm_read_byte( digital_pin_to_port_PGM + (P) ) )
#define digitalPinToBitMask(P) ( pgm_read_byte( digital_pin_to_bit_mask_PGM + (P) ) )
#define digitalPinToTimer(P) ( pgm_read_byte( digital_pin_to_timer_PGM + (P) ) )
#define analogInPinToBit(P) (P)
#define portOutputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_output_PGM + (P))) )
#define portInputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_input_PGM + (P))) )
#define portModeRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_mode_PGM + (P))) )

#define NOT_A_PIN 0
#define NOT_A_PORT 0

#define NOT_AN_INTERRUPT -1

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7
#define PH 8
#define PJ 10
#define PK 11
#define PL 12

// Standard Arduino functions
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
int analogRead(uint8_t pin);
void analogReference(uint8_t mode);
void analogWrite(uint8_t pin, int val);

unsigned long millis(void);
unsigned long micros(void);
void delay(unsigned long ms);
void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode);
void detachInterrupt(uint8_t interruptNum);

void setup(void);
void loop(void);

// Arduino Mega specific pin definitions
#define NUM_DIGITAL_PINS 70
#define NUM_ANALOG_INPUTS 16

// On the Arduino board, digital pins are also used for the analog output (PWM).
// Pins 2 to 13 (and 44-46 on the Arduino Mega) have PWM output.
#define digitalPinHasPWM(p) ((p) == 2 || (p) == 3 || (p) == 4 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 8 || (p) == 9 || (p) == 10 || (p) == 11 || (p) == 12 || (p) == 13 || (p) == 44 || (p) == 45 || (p) == 46)

// Analog pins
#define A0 54
#define A1 55
#define A2 56
#define A3 57
#define A4 58
#define A5 59
#define A6 60
#define A7 61
#define A8 62
#define A9 63
#define A10 64
#define A11 65
#define A12 66
#define A13 67
#define A14 68
#define A15 69

#define CS01 1

// External Interrupts
#define digitalPinToInterrupt(p) ((p) == 2 ? 0 : ((p) == 3 ? 1 : ((p) >= 18 && (p) <= 21 ? 23 - (p) : NOT_AN_INTERRUPT)))

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef __cplusplus
// C++ specific functions and classes

#if defined(HAVE_HWSERIAL0) && defined(HAVE_CDCSERIAL)
#error "Targets with both UART0 and CDC serial not supported"
#endif

uint16_t makeWord(uint16_t w);

#define word(...) makeWord(__VA_ARGS__)

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
void noTone(uint8_t _pin);

#endif // __cplusplus

#endif // Arduino_h
