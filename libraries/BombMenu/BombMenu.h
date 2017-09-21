/*
  BombMenu.h - Library for controling AirsoftDefusableBomb menu.
  Created by DMytro Horbachev, September 19, 2017.
  Released into the public domain.
*/
#ifndef BombMenu_h
#define BombMenu_h

#include "Arduino.h"
#include "BombLcd.h"

class BombMenu {
  public: 
    BombMenu(const BombLcd* lcdInstance);
    void resetTimer();
    void arm();
    void disarm();
    void printConfig();
    void changeMode(String newMode);
    void setMode(char key);
    void enterCode(char key);
    void setMasterCode();
    void validateCode();
    void reactToFailure();
    void resetCode();
    void resetMasterCode();
    void processKey(char key);
    void processKey(char key, bool armed);
    void resetState();
    void printInitialSetting();
    void disarmInProgress();
    void printDisarmMsg();
    bool armed;
    bool defused;
    String mode;
    bool inConfig;
    bool difusingInProgress;
  private:
    String code;
    String masterCode;
    bool masterCodeset;
    
    int timer;
    BombLcd* lcd;
};

#endif
