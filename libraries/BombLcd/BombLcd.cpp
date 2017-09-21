#include "Arduino.h"
#include "BombLcd.h"
#include "LiquidCrystal.h"
    
int cursorPointer = 0;

BombLcd::BombLcd(){
    lcd = new LiquidCrystal(0,1,2,3,4,5);
    lcd->begin(8,2);
}

void BombLcd::resetCursorPointer(){
    cursorPointer = 0;
}

void BombLcd::printFirstLine(String text){
    lcd->setCursor(0,0);
    lcd->print('        ');
    lcd->setCursor(0,0);
    lcd->print(text);
}

void BombLcd::printSecondLine(String text){
    lcd->setCursor(0,1);
    lcd->print('        ');
    lcd->setCursor(0,1);
    lcd->print(text);
}

void BombLcd::addToLine(int line, String text){
    lcd->setCursor(cursorPointer,line);
    lcd->print(text);
    cursorPointer++;
    delay(300);
}

void BombLcd::autoscrollOn()
{
    lcd->autoscroll();
}; 


void BombLcd::clear()
{
    lcd->clear();  
}
