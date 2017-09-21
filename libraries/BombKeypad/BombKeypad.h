/*
  BombKeypad.h - Library for controling AirsoftDefusableBomb keypad.
  Created by Dmytro Horbachev, September 19, 2017.
  Released into the public domain.
*/
#ifndef BombKeypad_h
#define BombKeypad_h

#include "Arduino.h"
#include "Keypad.h"

class BombKeypad{
  public: 
    BombKeypad();
    char listenToKeypad();
    char waitForKey();
  private:
    const byte ROWS;
    const byte COLS;
    char keys;
    byte rowPins;
    byte colPins;
    Keypad* keypad;
    char lastPressed;
};



#endif