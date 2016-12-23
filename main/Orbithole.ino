static void checkOptions(int * bt) {
  currentOption.left = 1;
  currentOption.up = 1;
  currentOption.right = 1;
  currentOption.down = 1;
  if ((bt - pathBool[0]) % horDivs == 0)
    currentOption.left = 0;
  if ((bt - pathBool[0] + 1) % horDivs  == 0)
    currentOption.right = 0;
  if ((bt - pathBool[0]) / horDivs == verDivs - 1)
    currentOption.down = 0;
  if ((bt - pathBool[0]) / horDivs == 0)
    currentOption.up = 0;
  if (currentOption.left)
    currentOption.left = !(*(bt - 1));
  if (currentOption.up)
    currentOption.up = !(*(bt - horDivs));
  if (currentOption.right)
    currentOption.right = !(*(bt + 1));
  if (currentOption.down)
    currentOption.down = !(*(bt + horDivs));
}

static void drawHole(void){
  int xMid = 8 + 14 * goalHole[0];
  int yMid = 6 + 10 * goalHole[1];
  OrbitOledMoveTo(xMid,yMid + 2);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid + 1,yMid + 2);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid,yMid + 2);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid + 2,yMid + 1);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid + 3,yMid);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid + 3,yMid - 1);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid + 2,yMid - 2);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid + 1,yMid - 3);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid,yMid - 3);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid - 1,yMid - 2);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid - 2,yMid - 1);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid - 2,yMid);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid - 1,yMid + 1);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid,yMid);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid + 1,yMid);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid,yMid -1);
  OrbitOledDrawPixel();
  OrbitOledMoveTo(xMid + 1,yMid - 1);
  OrbitOledDrawPixel();
}

static void updateMarble(void){
  marbleSpeed.x -= accel.x * PERIOD_S * MAX_MARBLE_ACC;
  marbleSpeed.y += accel.y * PERIOD_S * MAX_MARBLE_ACC;
  ptrMarbleCase = caseOption[0] + 9 * ((int)(marblePosition.y) / 10) + ((int)(marblePosition.x) / 14);
  int xMin = 2 + 14 * ((ptrMarbleCase - caseOption[0]) % 9);
  int xMax = xMin + 11;
  int yMin = 2 + 10 * ((ptrMarbleCase - caseOption[0]) / 9);
  int yMax = yMin + 7;
  if(!(ptrMarbleCase -> right) && (int)marblePosition.x + marbleSpeed.x * PERIOD_S + 3 > xMax){
    marbleSpeed.x *= -REBOUND_FACTR;
    marblePosition.x = xMax - 3;
  }
  if(!(ptrMarbleCase -> left) && (int)marblePosition.x + marbleSpeed.x * PERIOD_S < xMin){
    marbleSpeed.x *= -REBOUND_FACTR;
    marblePosition.x = xMin;
  }
  if(!(ptrMarbleCase -> down) && (int)marblePosition.y + marbleSpeed.y * PERIOD_S> yMax - 3){
    marbleSpeed.y *= -REBOUND_FACTR;
    marblePosition.y = yMax - 3;
  }
  if(!(ptrMarbleCase -> up) && (int)marblePosition.y + marbleSpeed.y * PERIOD_S < yMin){
    marbleSpeed.y *= -REBOUND_FACTR;
    marblePosition.y = yMin;
  }
  marblePosition.x += marbleSpeed.x * PERIOD_S;
  marblePosition.y += marbleSpeed.y * PERIOD_S;
  if((marblePosition.x - goalHole[0]) * (marblePosition.x - goalHole[0]) + (marblePosition.y - goalHole[1]) * (marblePosition.y - goalHole[1]) <= 4){
    gameState = 3;
    return;
  }
  for (int i = 0; i <= verDivs; i++) {
    OrbitOledMoveTo(0, i * (crowOledMax - 2) / verDivs);
    OrbitOledLineTo(ccolOledMax, i * (crowOledMax - 2) / verDivs);
    OrbitOledMoveTo(0, i * (crowOledMax - 2) / verDivs + 1);
    OrbitOledLineTo(ccolOledMax, i * (crowOledMax - 2) / verDivs + 1);
  }
  for (int i = 0; i <= horDivs; i++) {
    OrbitOledMoveTo(i * (ccolOledMax - 2) / horDivs, 0);
    OrbitOledLineTo(i * (ccolOledMax - 2) / horDivs, crowOledMax);
    OrbitOledMoveTo(i * (ccolOledMax - 2) / horDivs + 1, 0);
    OrbitOledLineTo(i * (ccolOledMax - 2) / horDivs + 1, crowOledMax);
  }
    OrbitOledSetFillPattern(OrbitOledGetStdPattern(iptnBlank));
    OrbitOledSetDrawMode(modOledSet);
      for(int i = 1; i < 26; i += 2){
      OrbitOledMoveTo(2 + 14 * (i % 9), 2 + 10 * (i / 9));
      if((caseOption[0] + i) -> up){
        OrbitOledFillRect(13 + 14 * ((i - 9) % 9), 9 + 10 * ((i - 9) / 9));
      }
      //OrbitOledMoveTo(2 + 14 * (i % 9), 2 + 10 * (i / 9));
      if((caseOption[0] + i) -> left){
        OrbitOledFillRect(13 + 14 * ((i - 1) % 9), 9 + 10 * ((i - 1) / 9));
      }
      //OrbitOledMoveTo(2 + 14 * (i % 9), 2 + 10 * (i / 9));
      if((caseOption[0] + i) -> right){
        OrbitOledFillRect(13 + 14 * ((i + 1) % 9), 9 + 10 * ((i + 1) / 9));
      }
      //OrbitOledMoveTo(2 + 14 * (i % 9), 2 + 10 * (i / 9));
      if((caseOption[0] + i) -> down){
        OrbitOledFillRect(13 + 14 * ((i + 9) % 9), 8 + 10 * ((i + 9) / 9));
      }
    }
}

static void DrawBall(){
  OrbitOledMoveTo((int)marblePosition.x + 1, (int)marblePosition.y);
  OrbitOledDrawPixel();
  OrbitOledMoveTo((int)marblePosition.x + 2, (int)marblePosition.y);
  OrbitOledDrawPixel();
  OrbitOledMoveTo((int)marblePosition.x + 2, (int)marblePosition.y + 3);
  OrbitOledDrawPixel();
  OrbitOledMoveTo((int)marblePosition.x + 1, (int)marblePosition.y + 3);
  OrbitOledDrawPixel();
  OrbitOledMoveTo((int)marblePosition.x, (int)marblePosition.y + 1);
  OrbitOledDrawPixel();
  OrbitOledMoveTo((int)marblePosition.x, (int)marblePosition.y + 2);
  OrbitOledDrawPixel();
  OrbitOledMoveTo((int)marblePosition.x + 3, (int)marblePosition.y + 1);
  OrbitOledDrawPixel();
  OrbitOledMoveTo((int)marblePosition.x + 3, (int)marblePosition.y + 2);
  OrbitOledDrawPixel();
  OrbitOledUpdate();
}

void orbitholeLoop(void) {
  OrbitOledClearBuffer();
  getAccel();
  updateMarble();
  DrawBall();
  drawHole();
  checkReset();
}

void orbitholeInit(void) {
  pathBool[0][0] = 1;
  srand(millis());
  struct options *pt = caseOption[0];
  for (int *bt = pathBool[0], n = 0; n <= 25; n++) {
    checkOptions(bt);
    if (currentOption.left + currentOption.up + currentOption.right + currentOption.down == 0) {
      endPoint[(bt - pathBool[0]) % horDivs][(bt - pathBool[0]) / horDivs] = 1;
      do {
        int k = n - rand() % (n - 1) - 1;
        pt = caseOption[0] + pathPoints[k].x + horDivs * pathPoints[k].y;
        bt = pathBool[0] + pathPoints[k].x + horDivs * pathPoints[k].y;
        checkOptions(bt);
      } while (currentOption.left + currentOption.up + currentOption.right + currentOption.down == 0);
    }
    int k = rand() % (currentOption.left + currentOption.up + currentOption.right + currentOption.down);
    int counter = 0;
    if (currentOption.left && counter ++ == k)
            pt -> left = 1, (--pt) -> right = 1, bt--;
    if (currentOption.up && counter ++ == k)
      pt -> up = 1, pt -= horDivs, pt -> down = 1, bt -= horDivs;
    if (currentOption.right && counter ++ == k)
      pt -> right = 1, (++pt) -> left = 1, bt++;
    if (currentOption.down && counter ++ == k)
      pt -> down = 1, pt += horDivs, pt -> up = 1, bt += horDivs;
    *bt = 1;
    pathPoints[n].x = (bt - pathBool[0]) % horDivs;
    pathPoints[n].y = (bt - pathBool[0]) / horDivs;
  }
  for (int i = 0; i <= verDivs; i++) {
    OrbitOledMoveTo(0, i * (crowOledMax - 2) / verDivs);
    OrbitOledLineTo(ccolOledMax, i * (crowOledMax - 2) / verDivs);
    OrbitOledMoveTo(0, i * (crowOledMax - 2) / verDivs + 1);
    OrbitOledLineTo(ccolOledMax, i * (crowOledMax - 2) / verDivs + 1);
  }
  for (int i = 0; i <= horDivs; i++) {
    OrbitOledMoveTo(i * (ccolOledMax - 2) / horDivs, 0);
    OrbitOledLineTo(i * (ccolOledMax - 2) / horDivs, crowOledMax);
    OrbitOledMoveTo(i * (ccolOledMax - 2) / horDivs + 1, 0);
    OrbitOledLineTo(i * (ccolOledMax - 2) / horDivs + 1, crowOledMax);
  }
    OrbitOledSetFillPattern(OrbitOledGetStdPattern(iptnBlank));
    OrbitOledSetDrawMode(modOledSet);
    for(int i = 1; i < 26; i += 2){
      OrbitOledMoveTo(2 + 14 * (i % 9), 2 + 10 * (i / 9));
      if((caseOption[0] + i) -> up)
        OrbitOledFillRect(13 + 14 * ((i - 9) % 9), 9 + 10 * ((i - 9) / 9));
      if((caseOption[0] + i) -> left)
        OrbitOledFillRect(13 + 14 * ((i - 1) % 9), 9 + 10 * ((i - 1) / 9));
      if((caseOption[0] + i) -> right)
        OrbitOledFillRect(13 + 14 * ((i + 1) % 9), 9 + 10 * ((i + 1) / 9));
      if((caseOption[0] + i) -> down)
        OrbitOledFillRect(13 + 14 * ((i + 9) % 9), 8 + 10 * ((i + 9) / 9));
    }
    for(int i = horDivs * verDivs; i > 0; i--)
      if(endPoint[i / horDivs][i % horDivs]){
        goalHole[0] = i / horDivs;
        goalHole[1] = i % horDivs;
        drawHole();
        break;
      }
  initGame = 1;
}
void gameWon(void){
  OrbitOledClear();
  OrbitOledSetCursor(3,1);
  OrbitOledPutString("YOU MADE IT!");
  delay(1000);
}

void gameLost(void){
  OrbitOledClear();
  OrbitOledSetCursor(0,1);
  OrbitOledPutString("YOU FEll IN THE");
  OrbitOledSetCursor(5,2);
  OrbitOledPutString("HOLE!");
  delay(1000);
}
