#define PERIOD_MS 40
#define PERIOD_S 40.0/1000.0
#define PX_M_RATIO 400.0/1.5
#define REBOUND_FACTR 0.2f
#define MAX_MARBLE_ACC 50
#include <math.h>
struct floatVector{
  double x;
  double y;
};
struct intVector{
  int x;
  int y;
};
struct intVector marblePosition = {.x = 1, .y = 1};
struct floatVector marbleSpeed = {.x = 0, .y = 0};
extern char    rgbOledBmp[];
