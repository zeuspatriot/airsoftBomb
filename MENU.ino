// bool ARMED = false;
// int timer = 0;
// String mode = "hold";
// String code = "";
// String masterCode = "";
// bool masterCodeSet = false;
// int getTimer () 
// {
//  return timer;
// }
// String getMode (){
//  return mode;
// }
// void resetBombVars()
// {
//  ARMED = false;
//  timer = 0;  
// }
// void typeInCode(char key){
//  if(!masterCodeSet){
//    typeInMasterCode(key);
//  }
//  else{
//    code += String(key);
//    addToLine(1, String(key));  
//  }
// }
// void typeInMasterCode(char key){
//  masterCode += String(key);
//  addToLine(1, String(key));
// }
// void resetCode(){
//  code = "";
// }
// void resetMasterCode(){
//  masterCode="";
//  masterCodeSet = false;
// }
// bool validatecode(){
//  return code == masterCode;
// }
// void menuProcessKey(char key)
// {
//  switch(key)
//  {   
//    case '1' :
//      if(ARMED && mode == "code"){
//        typeInCode(key);
//      }
//      if(!ARMED)
//      {
//        ARMED = true;
//        lcdClear();
       
//        if(mode == "hold"){
//          lcdPrintFirstLine("Bomb is");
//          lcdPrintSecondLine("Armed");
//          delay(3000);
 
//          lcdClear();
       
//          lcdPrintFirstLine("Hold '#'");
//          lcdPrintSecondLine("to DEFUSE");  
//        }
//        if(mode == "code"){
//          lcdPrintFirstLine("SET CODE");
//        }
       
//      }
//      break;
    
//    case '2' :
//      if(ARMED && mode == "code"){
//        typeInCode(key);
//      }
//      if(!ARMED)
//      {
//        lcdClear();
//        lcdPrintFirstLine("4-Hold");
//        lcdPrintSecondLine("7-Code");
//      }
//      break;

//    case '3' :
//      if(ARMED && mode == "code"){
//        typeInCode(key);
//      }
//      break;
   
//    case '4' :
//      if(ARMED && mode == "code"){
//        typeInCode(key);
//      }
//      if(!ARMED)
//      {
//        mode = "hold";
//        lcdClear();
//        lcdPrintFirstLine("Mode is:");
//        lcdPrintSecondLine(mode);
// //        delay(1000);
//        //setMainScreen();
//      }
//      break;

//    case '5' :
//      if(ARMED && mode == "code"){
//        typeInCode(key);
//      }
//      break;

//    case '6' :
//      if(ARMED && mode == "code"){
//        typeInCode(key);
//      }
//      break;
     
//    case '7' :
//      if(ARMED && mode == "code"){
//        typeInCode(key);
//      }
//      if(!ARMED)
//      {
//        mode = "code";
//        lcdClear();
//        lcdPrintFirstLine("Mode is:");
//        lcdPrintSecondLine(mode);
// //        delay(1000);
// //        setMainScreen();
//      }
//      break;

//    case '8' :
//      if(ARMED && mode == "code"){
//        typeInCode(key);
//      }
//      break;

//    case '9' :
//      if(ARMED && mode == "code"){
//        typeInCode(key);
//      }
//      break;
     
//    case '#' :
//      if(ARMED && mode == "code" && !masterCodeSet){
//        masterCodeSet = true;
//        delay(300);
//        lcdResetCursorPointer();
//        lcdClear();
//        lcdPrintFirstLine("CODE:");
//        return;
//      }
//      if(ARMED && mode == "code"){
//        if(validatecode()){
//          disarm();
//          lcdResetCursorPointer();
//          resetCode();
//        }
//        else{
//          lcdClear();
//          resetCode();
//          lcdResetCursorPointer();
//          lcdPrintFirstLine("WRONG");
//          lcdPrintSecondLine("CODE!");
//          delay(1000);
//          lcdClear();
//          lcdPrintFirstLine("CODE:");
//        }
//      }
//      if(ARMED && mode == "hold")
//      {
//        timer++;
//        String timerStr(timer);
//        lcdClear();
//        lcdPrintFirstLine("DEFUSING");
//        lcdPrintSecondLine(timerStr + "%");
// //        tone(buzzer, 1000);
//        delay(100);
//      }
//      break;

//    case '*' :
//      if(ARMED && mode == "code"){
//        lcdClear();
//        lcdPrintFirstLine("CODE:");
//        lcdResetCursorPointer();
//        resetCode();
//      }
//      break;

   

//    default:
//      ;
//  }
// }
