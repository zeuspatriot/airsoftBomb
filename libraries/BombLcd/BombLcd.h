/*
  BombLcd.h - Library for controling AirsoftDefusableBomb LCD screen.
  Created by DMytro Horbachev, September 19, 2017.
  Released into the public domain.
*/
#ifndef BombLcd_h
#define BombLcd_h

#include "Arduino.h"
#include "LiquidCrystal.h"

class BombLcd{
  public: 
    BombLcd();
    void printFirstLine(String text);
    void printSecondLine(String text);
    void clear();
    void autoscrollOn();
    void resetCursorPointer();
    void addToLine(int line, String text);
  private:
    LiquidCrystal* lcd;
    int cursorPointer;
};



#endif