#include <avr/io.h>

void setup()
{
  // For timer1. Perhaps a horrible waste of a 16-bit timer, but this has 
  // ICR1 which allows us to use both outputs bound to the timer.
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // Prescaler = 1, set port B inverted, Phase corrected PWM.
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(COM1B0) | _BV(WGM11);
  TCCR1B = _BV(CS10) | _BV(WGM13);

  ICR1 = 80; // Prescaler=1, so 16Mhz/80 = 100Khz
  OCR1A = 40; // 50% duty cycle
  OCR1B = 40;
}

void loop()
{
  exit(0);
}
