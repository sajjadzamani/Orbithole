#include <delay.h>
#include <math.h>
#include <stdlib.h>
#include <Wire.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>

#define PERIOD_MS 40
#define PERIOD_S 40.0/1000.0
#define NUM_GAMES 2

void getAccel(void);
void accelerometerInit(void);
void WireInit(void);
void moveCursor(int coloumn, int row, int game);
void menuStart();
void menuInit();
void gameLost(void);
void gameWon(void);
const uint32_t Buttons[2] = { PD_2, PE_0 };
extern int ychOledMax;
extern int xchOledMax;

struct minigame{
  char *name;
  int nameLength;
  int isInit;
};

struct minigame OrbitHole = {.name = "OrbitHole", .nameLength = 9, .isInit = 0 };
struct minigame EndorHunt = {.name = "EndorHunt", .nameLength = 9, .isInit = 0 };

#include "Motion.h"
#include "Orbithole.h"
#include "Menu.h"

int gameState = 0;

/*
Defines the state of the game
 0: main menu
 1: game1 start
 2: game1 death
 3: game1 win
 4: game2 start
 5: game1 death
 6: game1 win
 ...
 3N + 1: gameN start
 3N + 2: gameN death
 3N + 3: gameN win
 */

int initGame = 0;

void setup() {
  OrbitOledInit();
  WireInit();
  for(int i=0; i<2; i++)
    pinMode(Buttons[i],INPUT);
  accelerometerInit();
  menuInit();
  Serial.begin(9600);
}

void loop() {
  switch(gameState){
  case 0:
    menuStart();
    //if(!initGame)
     // men();
    break;
  case 1:
      if(!initGame)
        orbitholeInit();
      else
        orbitholeLoop();
    break;
  case 2:
    gameLost();
    break;
  case 3:
    gameWon();
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
 delay(PERIOD_MS);
}
