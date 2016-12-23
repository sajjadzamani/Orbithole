#ifndef ORBITHOLE_H
#define ORBITHOLE_H
#define REBOUND_FACTR 0.4f
#define MAX_MARBLE_ACC 50
#define INSTANT_ACCEL_COEF 0
struct floatVector{
  double x;
  double y;
  double z;
};
struct intVector{
  int x;
  int y;
};
struct options {
  int left;
  int up;
  int right;
  int down;
};

struct selector{
  int posMenu;
  int direction;
}selector;

const int horDivs = 9;
const int verDivs = 3;
int pathBool[horDivs][verDivs] = {0};
struct intVector pathPoints [26] = {0};
struct options caseOption[horDivs][verDivs] = {0};
struct options currentOption;
struct floatVector marblePosition = {.x = 6.0, .y = 4.0};
struct floatVector marbleSpeed = {.x = 0, .y = 0};
struct floatVector accel = {0};
int endPoint[horDivs][verDivs];
struct options * ptrMarbleCase = caseOption[0];
int goalHole[2] = {-1};
extern char    rgbOledBmp[];

static void checkOptions(int * bt);
static void updateMarble(void);
static void DrawBall();

void orbitholeLoop(void);
void orbitholeInit(void);
void gameWon(void);
void gameLost(void);
#endif
