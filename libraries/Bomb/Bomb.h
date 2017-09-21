/*
  Bomb.h - Library for controling AirsoftDefusableBomb.
  Created by Dmytro Horbachev, September 19, 2017.
  Released into the public domain.
*/
#ifndef Bomb_h
#define Bomb_h

#include "Arduino.h"
// #include "BombKeypad.h"
#include "BombLcd.h"
#include "BombMenu.h"

class Bomb{
  public: 
    Bomb();
    void tick(char key);
    // char getKey();
    // BombKeypad* keypad;
    String getMode();
    bool isArmed();
    bool isDifusing();
    BombMenu* menu;
  private:
    BombLcd* lcd;

    void handleDisarm(char key);
};



#endif