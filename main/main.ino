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
int gameState = 1;

/*
Defines the state of the game
 0: main menu
 1: marble start
 2: marble death
 3: marble win
 4: ship st art
 5: ship death
 6: ship win
 */
int selector = 0;
/*
 Defines which game is selected
0 * 128: OrbitHole
1 * 128: EndorHunt
Any other game we could add...
N * 128: Game N
*/
bool initGame = false;

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
    if(!initGame)
      menu_init();
    break;
  case 1:
    marble_start();
    if(!initGame)
      marble_init();
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
