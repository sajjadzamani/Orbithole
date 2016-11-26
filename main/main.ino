#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include "Ball.h"
void marble_start(void);
void getAccel(void);
void accelerometerInit(void);
void MoveBall(void);
void WireInit(void);
extern int ychOledMax;
extern int xchOledMax;
int gameState = 1;

/*
Defines the state of the game
 0: main menu
 1: marble start
 2: marble death
 3: marble win
 4: ship start
 5: ship death
 6: ship win
 */
int selector = 0;
/*
 Defines which game is selected
0: OrbitHole
100: EndorHunt
*/
void setup() {
  OrbitOledInit();
  WireInit();
  accelerometerInit();
  Serial.begin(9600);
}

void drawCanvas(void){
  switch(gameState){
  case 0:
    menu_start();
    break;
  case 1:
    marble_start();
    break;
  case 2:
    // TODO: Death animation
    break;
  case 3:
    // TODO: Win animation
    break;
  case 4:
    //  TODO: Ennemies, collectibles, lives, animation
    break;
  case 5:
    // TODO: Death animation
    break;
  case 6:
    // TODO: Win animation
    break;
  }
  OrbitOledUpdate();
}



void loop() {
 drawCanvas();
 delay(PERIOD_MS);
}
