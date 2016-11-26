
#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>

#include "Ball.h"
void marble_init(void);

  void Move();
  void MoveInit();
  void MoveBall();
  void WireInit();
  extern int    ychOledMax;
  extern int    xchOledMax;
  uint16_t xi;
  uint16_t yi;
  uint16_t zi;
  float Ax, Ay, Az;
  int gameState = 0;
  // Defines the state of the game
  // 0: main menu
  // 1: marble start
  // 2: marble death
  // 3: marble win
  // 4: ship start
  // 5: ship death
  // 6: ship win
  int selector = 0;
  // Defines which game is selected
  // 0: marble
  // 100: ship
  int i = 0;
void setup() {
  OrbitOledInit();
  WireInit();
  MoveInit();
  Serial.begin(9600);
}
/*
void drawCanvas(void){
  switch(gameState){
  case 0:
    //menu_start();
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
<<<<<<< .mine
OrbitOledUpdate();
}
||||||| .r2325
}
=======
}*/
>>>>>>> .r2523

void loop() {
 MoveBall();
 delay(40);
// drawCanvas();
 // TODO: BTNs, Accelerometer
<<<<<<< .mine
 delay(PERIOD_S);
||||||| .r2325
 delay(40);
=======

>>>>>>> .r2523
}
