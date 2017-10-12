#include "Arduino.h"
#include "BombMenu.h"


bool armed = false;
bool defused = false;
int timer = 0;
typedef BombLcd lcd;
bool inConfig = false;
String mode = "hold";
String code = "";
String masterCode = "";
bool masterCodeSet = false;
bool difusingInProgress = false;

BombMenu::BombMenu(const BombLcd* lcdScreen){
    lcd = lcdScreen;
}

void BombMenu::resetState(){
  armed = false;
  defused = false;
  timer = 0;
  inConfig = false;
  mode = "hold";
  code = "";
  masterCode = "";
  masterCodeSet = false;
  difusingInProgress = false;
}

void BombMenu::printInitialSetting(){
  lcd->clear();
  lcd->printFirstLine("1-ARM");
  lcd->printSecondLine("2-Config");
}

void BombMenu::resetTimer(){
    timer = 0;
    difusingInProgress = false;
}

void BombMenu::arm(){
  Serial.println("ARM!!");
  armed = true;
  if(mode == "hold"){
    lcd->clear();
    lcd->printFirstLine("Bomb is");
    lcd->printSecondLine("ARMED!");
    delay(1000);
    printDisarmMsg();
  }
  else if(mode == "code"){
    lcd->clear();
    lcd->printFirstLine("Set Code");
    lcd->resetCursorPointer();
  }
}
void BombMenu::printDisarmMsg(){
  lcd->clear();
  lcd->printFirstLine("Hold '#'");
  lcd->printSecondLine("ToDisarm");
}

void BombMenu::disarm(){
  armed = false;
  defused = true;

  lcd->clear();
  lcd->printFirstLine("DEFUSED!");

  delay(3000);
  lcd->clear();
  resetState();
  printInitialSetting();
}

void BombMenu::printConfig(){
  inConfig = true;
  lcd->clear();
  lcd->printFirstLine("1-Hold");
  lcd->printSecondLine("2-Code");
}

void BombMenu::changeMode(String newMode){
  mode = newMode;
  lcd->clear();
  inConfig = false;
  printInitialSetting();
}

void BombMenu::disarmInProgress(){
  if(timer == 100){
    disarm();
  }
  else{
    difusingInProgress = true;
    delay(200);
    lcd->clear();
    timer++;
    String timerStr = String(timer);
    lcd->printFirstLine("DIFUSING");
    lcd->printSecondLine("--" + timerStr + "%--");
  }

}

void BombMenu::setMode(char key){
  switch(key){
    case '1':
      changeMode("hold");
      break;

    case '2':
      changeMode("code");
      break;

    default:
      ;
  }
}
void BombMenu::enterCode(char key){
  if(masterCodeSet){
    code = code + String(key);
  }
  else{
    masterCode = masterCode + String(key);
  }
  lcd->addToLine(1, String(key));
}

void BombMenu::setMasterCode(){
  masterCodeSet = true;
  lcd->resetCursorPointer();
  lcd->clear();
  lcd->printFirstLine("CODE:");
}

void BombMenu::validateCode(){
  lcd->resetCursorPointer();
  if(code == masterCode) {
    disarm();
  }
  else{
    reactToFailure();
  }
}

void BombMenu::reactToFailure(){
  lcd->clear();
  lcd->printFirstLine("WRONG");
  lcd->printSecondLine("CODE!");
  code = "";
  delay(1000);

  lcd->clear();
  lcd->printFirstLine("CODE:");
}

void BombMenu::resetCode(){
  code = "";
  lcd->clear();
  lcd->printFirstLine("CODE:");
  lcd->resetCursorPointer();
}

void BombMenu::resetMasterCode(){
  masterCode = "";
  lcd->clear();
  lcd->printFirstLine("Set Code");
  lcd->resetCursorPointer();
}

void BombMenu::processKey(char key){
    switch(key)
    {
      case '1' :
        arm();
        break;
      
      case '2' :
        printConfig();
        break;
      
      case '3' :
        
        break;
      
      case '4' :
        
        break;
      
      case '5' :
        
        break;
      
      case '6' :
        
        break;
      
      case '7' :
        
        break;
      
      case '8' :
        
        break;
      
      case '9' :
        
        break;
      
      case '0' :
        
        break;
      
      case '*' :
        
        break;
      
      case '#' :
        
        break;
  
      default:
        ;
    }
}

void BombMenu::processKey(char key, bool armed){
  Serial.println("In code process char");
  if(mode=="code"){
    if(key == '*'){
      masterCodeSet ? resetCode() : resetMasterCode();
    }
    else if(key == '#'){
      masterCodeSet ? validateCode() : setMasterCode();
    }
    else{
      enterCode(key);
    }
  }
  else{
    if(key == '#'){
      disarmInProgress();
    }
  }
  
}