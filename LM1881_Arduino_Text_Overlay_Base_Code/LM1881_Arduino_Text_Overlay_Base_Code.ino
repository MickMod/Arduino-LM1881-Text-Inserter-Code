#include <TVout.h>
#include <fontALL.h>

#define W 136
#define H 96 

TVout TV;
unsigned char x,y;


void setup () {
  TV.begin(PAL, W, H);
  initOverlay();
  TV.select_font(font6x8);
  TV.fill(0);
}


// Initialize ATMega registers for video overlay capability.
// Must be called after tv.begin().
void initOverlay() {
  TCCR1A = 0;
  // Enable timer1.  ICES0 is set to 0 for falling edge detection on input capture pin.
  TCCR1B = _BV(CS10);

  // Enable input capture interrupt
  TIMSK1 |= _BV(ICIE1);

  // Enable external interrupt INT0 on pin 2 with falling edge.
  EIMSK = _BV(INT0);
  EICRA = _BV(ISC01);
}

// Required to reset the scan line when the vertical sync occurs
ISR(INT0_vect) {
  display.scanLine = 0;
}


void loop() {
  TV.println(0,0,"LINJE 1");
  TV.println(0,10,"LINJE 2");
  TV.println(0,20,"LINJE 3");
  TV.println(0,30,"LINJE 4");
}
