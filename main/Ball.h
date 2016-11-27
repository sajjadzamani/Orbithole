#define PERIOD_MS 40
#define PERIOD_S 40.0/1000.0
#define REBOUND_FACTR 0.6f
#define MAX_MARBLE_ACC 50
#define INSTANT_ACCEL_COEF 0.2f
#define NUM_OF_GAMES 2
#include <math.h>
struct floatVector{
  double x;
  double y;
};
struct intVector{
  int x;
  int y;
};
struct floatVector marblePosition = {.x = 1, .y = 1};
struct floatVector marbleSpeed = {.x = 0, .y = 0};
extern char    rgbOledBmp[];
struct floatVector accel = {0};
