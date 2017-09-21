#include "Arduino.h"
#include "Bomb.h"
// #include "BombKeypad.h"
#include "BombLcd.h"
#include "BombMenu.h"

Bomb::Bomb(){
    // keypad = new BombKeypad();
    lcd = new BombLcd();
    menu = new BombMenu(lcd);
}

String Bomb::getMode(){
    return menu->mode;
}

bool Bomb::isArmed(){
    return menu->armed;
}

bool Bomb::isDifusing(){
    return menu->difusingInProgress;
}

// char Bomb::getKey(){
//     if(getMode() == "hold"){
//         return keypad->listenToKeypad();
//     }
//     else{
//         return keypad->waitForKey();
//     }
//     Serial.print("getting key...");
// }

void Bomb::handleDisarm(char key){
    menu->processKey(key, isArmed());
}



void Bomb::tick(char key){
    // char key = getKey();
    if(key && key != 'q'){
        if(menu->inConfig){
            menu->setMode(key);   
        }
        else if(isArmed()){
            handleDisarm(key);
        }
        else{
            menu->processKey(key);
        }
    }
    else if(key == 'q' && isArmed() && getMode() == "hold" && isDifusing()){
        menu->resetTimer();
        menu->printDisarmMsg();
    }
    
}
