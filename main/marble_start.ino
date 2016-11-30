#include <stdlib.h>
const int horDivs = 9;
const int verDivs = 3;
struct intVector pathPoints [26] = {-1};
int pathBool[ccolOledMax][crowOledMax] = {0};
int endPoint[ccolOledMax][crowOledMax] = {0};


int * checkOptions(int * bt){
  /*
   * options[0] left
   * options[1] top
   * options[2] right
   * options[3] down
   */
  int options[4] = {1};
  if((bt - pathBool[0]) % ccolOledMax == 0)
    options[0] = 0;
  if((bt - pathBool[0] + 1) % ccolOledMax  == 0)
    options[2] = 0;
  if((bt - pathBool[0]) / 128 == 31)
    options[3] = 0;
  if((bt - pathBool[0]) / 128 == 0)
    options[1] = 0;
  if(options[0])
    options[0] = *(bt - 1);
  if(options[1])
    options[1] = *(bt - 128);
  if(options[2])
    options[2] = *(bt + 1);
  if(options[3])
    options[3] = *(bt + 128);
  return options;    
}
void marble_start(void){
  MoveBall();
}
void marble_init(void){
  **pathBool = 1;
  srand(millis());
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
  for(int i = 0; i <= verDivs ; i++){
    OrbitOledMoveTo(0,i * (crowOledMax - 2 * (verDivs + 1)) / 3 + 2 * i);
    OrbitOledLineTo(ccolOledMax,i * (crowOledMax - 2 * (verDivs + 1)) / 3 + 2 * i);
    OrbitOledMoveTo(0,i * (crowOledMax - 2 * (verDivs + 1)) / 3 + 2 * i + 1);
    OrbitOledLineTo(ccolOledMax,i * (crowOledMax - 2 * (verDivs + 1)) / 3 + 2 * i + 1);
  }
  initGame = true;
}

