#include "Arduino.h"
#include "BombKeypad.h"
#include <Keypad.h>

/********** KEYPAD START **********/
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};

byte rowPins[ROWS] = {7,12,11,13}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8,6,10}; //connect to the column pinouts of the keypad
/********** KEYPAD END **********/

BombKeypad::BombKeypad(){
  keypad = new Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
}
char lastPressed;
char BombKeypad::listenToKeypad(){
  char key = keypad->getKey();
  int isHeld = keypad->getState() - 0;

 Serial.println(key);
  if (key != NO_KEY){
//    Serial.println(isHeld);
    lastPressed = key;
    return lastPressed;
  }
  else if(isHeld > 0){
    // Serial.println(lastPressed);
    return lastPressed;  
  }
  else{
    return 'q';
  }
}
char BombKeypad::waitForKey(){
  char key = keypad->waitForKey();
  return key;  
}
