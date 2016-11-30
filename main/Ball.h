#include <math.h>

#define PERIOD_MS 40
#define PERIOD_S 40.0/1000.0
#define REBOUND_FACTR 0.6f
#define MAX_MARBLE_ACC 50
#define INSTANT_ACCEL_COEF 0.2f
#define MAX_X_SCREEN 128
#define MAX_Y_SCREEN 32
#define NUM_GAMES 2

struct floatVector{
  double x;
  double y;
  double z;
};

struct intVector{
  int x;
  int y;
};
struct selector{
  int posMenu;
  int direction;
}selector;

struct minigame{
  char *name;
  int nameLength;
  int isInit;
};
/*int *displayMenu [ccolOledMax][crowOledMax];
  void *initializer;
  void *looper;*/
struct floatVector marblePosition = {.x = 1, .y = 1};
struct floatVector marbleSpeed = {.x = 0, .y = 0};
struct floatVector accel = {0};

struct minigame OrbitHole = {.name = "OrbitHole", .nameLength = 9, .isInit = 0 };
struct minigame EndorHunt = {.name = "EndorHunt", .nameLength = 9, .isInit = 0 };

char menuBuffer [crowOledMax][NUM_GAMES*ccolOledMax] = {0x00};
char *txt = &(menuBuffer[0][0]);

/*
 Defines which game is selected
0 * 128: OrbitHole
1 * 128: EndorHunt
Any other game we could add...
N * 128: Game N
*/
