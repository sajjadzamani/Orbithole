#define SCREEN_DST 56
#define ORBIT_SCRN 0
#define ENDOR_SCRN 1
#define MENU_TILT_ANGL 30.0f
#define BTN_ACTV_ANGL  1.0f

int cornerBmp_x = (ccolOledMax-OrbitHole.nameLength*8)/2 -1; //27
int cornerBmp_y = (crowOledMax-8)/2 - 1; //11
const int widthBmp = 256;
const int heightBmp = 32;
char *instruction = "Press BTN1";

void tiltMenu(){
  double pitchAngle = pitch();
  if(pitchAngle < -MENU_TILT_ANGL)
    selector.direction= -1;    //anticlockwise
    else if(pitchAngle > MENU_TILT_ANGL)
         selector.direction = 1;    //clockwise
      else if(pitchAngle < BTN_ACTV_ANGL || pitchAngle > -BTN_ACTV_ANGL)
          selector.direction=0;

}

void menuInit(){
  OrbitOledClearBuffer();
  OrbitOledSetCursor(4,2);
  OrbitOledPutString("Welcome!");
  OrbitOledUpdate();
  moveCursor(cornerBmp_x,cornerBmp_y ,ORBIT_SCRN);
  putString(OrbitHole.name);
  moveCursor(cornerBmp_x,cornerBmp_y, ENDOR_SCRN);
  putString(EndorHunt.name);
  delay(1000);
  OrbitOledClear();
  OrbitOledMoveTo(cornerBmp_x,cornerBmp_y);
  moveCursor(cornerBmp_x,cornerBmp_y ,ORBIT_SCRN);
  OrbitOledPutBmp(widthBmp, heightBmp, txt);
  OrbitOledUpdate();
  selector.posMenu=0;
}

void menuStart(){
  int prevPos = selector.posMenu;
    tiltMenu();
    if(selector.posMenu != (128*(NUM_GAMES-1)) && selector.direction == 1){ //right tilt
      while((selector.posMenu - prevPos) != 128 ){
        txt+=selector.posMenu;
        OrbitOledClearBuffer();
        OrbitOledPutBmp(widthBmp, heightBmp, txt);
        OrbitOledUpdate();
        selector.posMenu++;
        /*
        }else{
        OrbitOledMoveTo(--cornerBmp_x,cornerBmp_y);
        OrbitOledPutBmp(widthBmp, heightBmp, txt);
        }*/
        delay(200);
        }
      }
    if(selector.posMenu != 0 && selector.direction == -1 ){  //left tilt
      while((prevPos-selector.posMenu) != 128 ){
        txt-=selector.posMenu;
        OrbitOledClearBuffer();
        OrbitOledPutBmp(widthBmp, heightBmp, txt);
        OrbitOledUpdate();
        selector.posMenu--;
        delay(200);
      }
    }
    if(selector.posMenu % 128 == 0 && selector.direction == 0){
      if(digitalRead(Buttons[0])){
        gameState=1+3*selector.posMenu / 128;
      }
    }
}

void checkReset(){
if(digitalRead(Buttons[1]) && (gameState - 1) % 3 == 0)
  gameState = 0;
}
