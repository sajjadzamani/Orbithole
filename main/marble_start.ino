#include <stdlib.h>
void marble_start(void){
  MoveBall();
}
void marble_init(void){
  srand(time(NULL));
  
  struct intVector pathPoints[8 + rand() % 2];
  pathPoints[0].x = marblePosition.x;
  pathPoints[0].y = marblePosition.y; 
  for(int k = 1; k < sizeof(pathPoints)/sizeof(struct intVector); k++){
    if(rand() % 2){
      pathPoints[k].x = pathPoints[k - 1].x;
      pathPoints[k].y = pathPoints[k - 1].y + rand() % (crowOledMax - pathPoints[k - 1].y - 2);
    }
    else{
      pathPoints[k].y = pathPoints[k - 1].y;
      pathPoints[k].x = pathPoints[k - 1].x + rand() % (ccolOledMax - pathPoints[k - 1].x - 2);
    }
  }
  for(int i = 0; i < sizeof(pathPoints)/sizeof(struct intVector) - 1; i++){
    OrbitOledMoveTo(pathPoints[i].x,pathPoints[i].y);
    OrbitOledLineTo(pathPoints[i + 1].x,pathPoints[i + 1].y);
  }
  initGame = true;
}

