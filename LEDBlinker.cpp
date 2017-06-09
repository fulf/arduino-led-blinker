#include "LEDBlinker.h"
 
  void LEDBlinker::init_pattern() {
    pattern[0] = 1;
    pattern[1] = 0;
    patternSize = 2;
    patternIndex = 0;
  }

  void LEDBlinker::init_led() {
    pinMode(ledPin, OUTPUT);
    ledState = HIGH;
    blinkedAt = millis();
    init_pattern();
  }
  
  LEDBlinker::LEDBlinker(int pin) {
    ledPin = pin;
    interval = 1000;
    init_led();
  }
  
  LEDBlinker::LEDBlinker(int pin, int ms_interval) {
  ledPin = pin;
  interval = ms_interval;
  init_led();
  }
  
  void LEDBlinker::set_interval(int ms_interval) {
    interval = ms_interval;
  }
  
  void LEDBlinker::set_pattern(int *p, int s) {
    patternSize = s;
    
    for(int i=0; i<patternSize; ++i)
      pattern[i] = p[i];
  }
  
  void LEDBlinker::blink() {
    unsigned long uptime = millis();
    
    if(uptime - blinkedAt >= interval || uptime < blinkedAt) {
      blinkedAt = uptime;
      
      toggle();
    }
  }
  
  void LEDBlinker::run_pattern() {
    unsigned long uptime = millis();
    if(uptime - blinkedAt >= interval || uptime < blinkedAt) {
      blinkedAt = uptime;
      
      pattern[patternIndex++] == 1 ? on() : off();
      
      if(patternIndex == patternSize)
        patternIndex = 0;
    }
  }
  
  void LEDBlinker::on() {
    ledState = LOW;
    digitalWrite(LED_BUILTIN, ledState);
  }
  
  void LEDBlinker::off() {
    ledState = HIGH;
    digitalWrite(LED_BUILTIN, ledState);
  }
  
  void LEDBlinker::toggle() {
    ledState = (ledState == LOW) ? HIGH : LOW;
    digitalWrite(LED_BUILTIN, ledState);
  }