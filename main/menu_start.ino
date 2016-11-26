
void menu_start(void){
  //char *instr[] = "Press BTN1 to start";
  switch(selector){
  case 0:
    //OrbitOledSetCursor((xchOledMax - (int)(sizeof("OrbitHole")) - 1) / 2, ychOledMax / 3); // Centers the title
    //OrbitOledPutString("OrbitHole");
    OrbitOledSetCursor(i++, ychOledMax); // Centers the subtitle
    for(int j = 0; j < 16; j++)
     // OrbitOledPutChar(*(instr + k));
    break;
  case 1:
    //OrbitOledSetCursor((xchOledMax - (int)(sizeof("Endorhunt")) - 1) / 2, ychOledMax / 2); // Centers the title
    //OrbitOledPutString("Endorhunt");
    //OrbitOledSetCursor((xchOledMax - (int)(sizeof("Press BTN1 to start")) - 1) / 2, ychOledMax); // Centers the subtitle
    //OrbitOledPutString("Press BTN1 to start");
    break;
  }
}
