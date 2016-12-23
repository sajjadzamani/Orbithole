#include "menu.h"
extern char *  pbOledFontUser;
extern char * pbOledFontCur;


void moveCursor(int column, int row, int game){
  txt = menuBuffer[0];
  txt += row * ccolOledMax * NUM_GAMES + column + game *  128;
}

void putChar(char ch){
  char *  pbFont;
  int   ib;
  if ((ch & 0x80) != 0) {
    return;
  }
  if (ch < chOledUserMax) {
    pbFont = pbOledFontUser + ch*cbOledChar;
  }
  else if ((ch & 0x80) == 0) {
    pbFont = pbOledFontCur + (ch-chOledUserMax) * cbOledChar;
  }
  for (ib = 0; ib < 8; ib++){
    *txt++ = *pbFont++;
  }
}

void putString(char *ch){
    while (*ch != '\0') {
    putChar(*ch);
    ch += 1;
  }
}


static void tiltMenu(void){
  getAccel();
  double pitchAngle = atan2(-accel.x,accel.z)*(180.0/M_PI);
  if(pitchAngle < -MENU_TILT_ANGLE)
    selector.direction= -1;    //anticlockwise
    else if(pitchAngle > MENU_TILT_ANGLE)
         selector.direction = 1;    //clockwise
      else if(pitchAngle < BTN_ACTV_ANGLE || pitchAngle > -BTN_ACTV_ANGLE)
          selector.direction=0;
}

void menuInit(void){
  OrbitOledClearBuffer();
  OrbitOledSetCursor(4,1);
  OrbitOledPutString("Welcome!");
  OrbitOledUpdate();
  moveCursor(cornerBmp_x,cornerBmp_y ,ORBIT_SCRN);
  putString(OrbitHole.name);
  moveCursor(cornerBmp_x,cornerBmp_y, ENDOR_SCRN);
  putString(EndorHunt.name);
  delay(1000);
  OrbitOledClear();
  OrbitOledMoveTo(0,cornerBmp_y);
  moveCursor(0,cornerBmp_y,ORBIT_SCRN);
  OrbitOledPutBmp(widthBmp, heightBmp, txt);
  OrbitOledUpdate();
  selector.posMenu=0;
}

void menuStart(void){
  OrbitOledMoveTo(0,cornerBmp_y);
  if(initGame == 1){
    OrbitOledPutBmp(widthBmp, heightBmp, txt);
    OrbitOledUpdate();
  }
  int prevPos = selector.posMenu;
  tiltMenu();
  if(selector.posMenu != (128*(NUM_GAMES-1)) && selector.direction == 1){ //right tilt
    while((selector.posMenu - prevPos) != 128 ){
      txt++;
      OrbitOledClearBuffer();
      OrbitOledPutBmp(widthBmp, heightBmp, txt);
      OrbitOledUpdate();
      selector.posMenu++;
      }
    prevPos=selector.posMenu;
  }
  //tiltMenu();
  if(selector.posMenu != 0 && selector.direction == -1 ){  //left tilt
     while((prevPos-selector.posMenu) != 128 ){
       txt--;
       OrbitOledClearBuffer();
       OrbitOledPutBmp(widthBmp, heightBmp, txt);
       OrbitOledUpdate();
       selector.posMenu--;
     }
   prevPos=selector.posMenu;
  }
  if(selector.posMenu % 128 == 0 && selector.direction == 0)
     if(digitalRead(Buttons[0]))
        gameState=1+3*selector.posMenu / 128;  //starts game
}

void checkReset(void){
  if(digitalRead(Buttons[1]) && (gameState - 1) % 3 == 0){
    gameState = 0;
    OrbitOledClear();
  }
}
