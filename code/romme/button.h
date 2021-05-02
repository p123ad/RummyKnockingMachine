/*
Button.h - Library for Buttons for the Romme machine
*/

#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  private:
      bool _state;
      uint8_t _pin;

  public:
      Button(uint8_t pin) : _pin(pin) {}

      void begin() {
        pinMode(_pin,INPUT);
        _state = digitalRead(_pin);
      }

      bool isPressed() {
        bool reading = digitalRead(_pin);
        if(reading) {
          return true;
        }
        return false;
      }
};

#endif