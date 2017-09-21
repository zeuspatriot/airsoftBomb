#include <Bomb.h>

const int buzzer = 9;

Bomb* bomb = new Bomb();
char greenLED = A0;
char redLED = A1;
void setup(){
    pinMode(buzzer, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);

    bomb->menu->resetState();
    bomb->menu->printInitialSetting();
}

void loop()
{
  if(bomb->isArmed()){
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);  
  }
  else{
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }
  char key;
  if(bomb->getMode() == "hold" && bomb->isArmed()){
        key = listenToKeypad();
    }
    else{
        key = waitForKey();
    }
  bomb->tick(key);
  
  
//  noTone(buzzer);
//  panScreen();
} // end loop()

