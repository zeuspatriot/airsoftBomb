#include <Keypad.h>

/********** KEYPAD START **********/
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
 {'1','2','3'},
 {'4','5','6'},
 {'7','8','9'},
 {'*','0','#'}
};

byte rowPins[ROWS] = {7,12,11,13}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8,6,10}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

/********** KEYPAD END **********/
char lastPressed;
char listenToKeypad(){
 char key = keypad.getKey();
 int isHeld = keypad.getState() - 0;

 if (key != NO_KEY){
   lastPressed = key;
   return lastPressed;
 }
 else if(isHeld > 0){
   return lastPressed;  
 }
 else{
   return 'q';  
 }
}
char waitForKey(){
 return keypad.waitForKey();  
}
