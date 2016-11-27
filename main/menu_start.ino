void menu_start(void){
  //char *instr[] = "Press BTN1 to start";
  switch(selector){
  case 0:
    //OrbitOledSetCursor((ccolOledMax - (int)(sizeof("OrbitHole")) - 1) / 2, crowOledMax / 3); // Centers the title
    //OrbitOledPutString("OrbitHole");
    //OrbitOledSetCursor(i++, crowOledMax); // Centers the subtitle
    for(int j = 0; j < 16; j++)
     // OrbitOledPutChar(*(instr + k));
    break;
  case 1:
    //OrbitOledSetCursor((ccolOledMax - (int)(sizeof("Endorhunt")) - 1) / 2, crowOledMax / 2); // Centers the title
    //OrbitOledPutString("Endorhunt");
    //OrbitOledSetCursor((ccolOledMax - (int)(sizeof("Press BTN1 to start")) - 1) / 2, crowOledMax); // Centers the subtitle
    //OrbitOledPutString("Press BTN1 to start");
    break;
  }
}
void menu_init(void){
  
}

