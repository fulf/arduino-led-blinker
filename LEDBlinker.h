#ifndef LED_BLINKER_H
#define LED_BLINKER_H

#include "Arduino.h"

class LEDBlinker
{
  private: 
    unsigned long blinkedAt;
    int interval,
      ledPin,
      ledState,
      pattern[20],
      patternSize,
      patternIndex;
    void init_pattern();
    void init_led();

  public:
    LEDBlinker(int pin);
    LEDBlinker(int pin, int ms_interval); 
    void set_interval(int);
    void set_pattern(int *p, int s);
    void blink();
    void run_pattern();
    void on();
    void off();
    void toggle();
};

#endif