#include <stdlib.h>
#include <stdio.h>
void marble_start(void){
    time_t t;
  srand((unsigned) time(&t));
  int pathPoints[8 + rand() % 2][2];
  pathPoints[0][0] = 4;
  pathPoints[0][1] = ychOledMax - 4;
  for(int k = 1; k < sizeof(pathPoints)/sizeof(int); k++){
    if(rand() % 2){
      pathPoints[k][0] = pathPoints[k - 1][0];
      pathPoints[k][1] = pathPoints[k - 1][1] + rand() % (ychOledMax - pathPoints[k - 1][1] - 2);
    }
    else{
      pathPoints[k][1] = pathPoints[k - 1][1];
      pathPoints[k][0] = pathPoints[k - 1][0] + rand() % (xchOledMax - pathPoints[k - 1][0] - 2);
    }
  }
  for(int i = 0; i < sizeof(pathPoints)/sizeof(pathPoints[0]); i++){
    OrbitOledMoveTo(pathPoints[i][0],pathPoints[i][1]);
    OrbitOledLineTo(pathPoints[i][2],pathPoints[i][3]);
  }
  DrawBall();
}
