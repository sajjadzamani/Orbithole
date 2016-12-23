#ifndef MENU_H
#define MENU_H

#define ORBIT_SCRN 0
#define ENDOR_SCRN 1
#define MENU_TILT_ANGLE 30.0f
#define BTN_ACTV_ANGLE  1.0f

char menuBuffer[32][NUM_GAMES*128]={0x00};
char *txt;
const int cornerBmp_x = (ccolOledMax-OrbitHole.nameLength*8)/2 -1; //27
const int cornerBmp_y = (crowOledMax-8)/2 - 1; //11
const int widthBmp = 256;
const int heightBmp = 32;
#endif
