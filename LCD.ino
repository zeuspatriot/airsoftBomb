// // include the library code:
// #include <LiquidCrystal.h>

// LiquidCrystal lcd(0,1,2,3,4,5);
// int positioncounter = 0;
// int maxTextLength = 0;
// String direction = "left";
// int cursorPosition = 0;
// void initLcd()
// {
//  lcd.begin(8,2);
// };
// void lcdResetCursorPointer(){
//  cursorPosition = 0;
// }
// void lcdPrintFirstLine(String text)
// {
//  setNewMaxLength(text.length());

//  lcd.setCursor(0,0);
//  lcd.print(text);
// };
// void lcdPrintSecondLine(String text)
// {
//  setNewMaxLength(text.length());

//  lcd.setCursor(0,1);
//  lcd.print(text);
// };
// void addToLine(int line, String text){
//  lcd.setCursor(cursorPosition,line);
//  lcd.print(text);
//  cursorPosition++;
//  delay(300);
// }

// void autoscrollOn()
// {
//  lcd.autoscroll();
// };  

// void lcdClear()
// {
//  lcd.clear();  
// }

// void setMainScreen(){
//  lcdClear();
//  lcdPrintFirstLine("1-Arm");
//  lcdPrintSecondLine("2-Config");
// }

// static void setNewMaxLength(int newLength)
// {
//  if(newLength > maxTextLength)
//  {
//    positioncounter = 0;
//    maxTextLength = newLength;
//  }
// }

// void panScreen(){
//  delay(400);
//  if(direction == "right"){
//    lcd.scrollDisplayRight();
//    positioncounter--;
//    if(positioncounter == 0){
//      delay(700);
//      direction = "left";
//    }
//  }
//  else{
//    lcd.scrollDisplayLeft();
//    positioncounter++;
//    if(positioncounter == maxTextLength - 8){
//      delay(700);
//      direction = "right";
//    }
//  }
// }
