/*Keep this for now
* Roll angle:
double getRoll( float accel.x, float Az){

return atan(-accel.x/Az)*(180/3.14);
}*/
struct floatVector GetSpeed(){
  if(marblePosition.x > 124 || marblePosition.x < 0 || marblePosition.y > 28 || marblePosition.y < 0){
    if(marblePosition.x > 124 || marblePosition.x < 0){
      marbleSpeed.x *= -REBOUND_FACTR;
      marblePosition.x = (marblePosition.x >= 124) ? 124 : 0;
      if(marblePosition.y > 28 || marblePosition.y < 0){
        marbleSpeed.y *= -REBOUND_FACTR;
        marblePosition.y = (marblePosition.y >= 28) ? 28 : 0;
      }
      else
        marbleSpeed.y += accel.y * PERIOD_S * MAX_MARBLE_ACC;
    }
    if(marblePosition.y > 28 || marblePosition.y < 0){
      marbleSpeed.y *= -REBOUND_FACTR;
      marblePosition.y = (marblePosition.y >= 28) ? 28 : 0;
      if(marblePosition.x > 124 || marblePosition.x < 0){
        marbleSpeed.x *= -REBOUND_FACTR;
        marblePosition.x = (marblePosition.x >= 124) ? 124 : 0;
      }
      else
        marbleSpeed.x -= accel.x * PERIOD_S * MAX_MARBLE_ACC;
    }
  }
  else{
    marbleSpeed.x -= accel.x * PERIOD_S * MAX_MARBLE_ACC;
    marbleSpeed.y += accel.y * PERIOD_S * MAX_MARBLE_ACC;
  }
  return marbleSpeed;
}

struct floatVector GetPosition(){
  marblePosition.x += (1 - INSTANT_ACCEL_COEF) * marbleSpeed.x * PERIOD_S - INSTANT_ACCEL_COEF * MAX_MARBLE_ACC * PERIOD_S * accel.x;
  marblePosition.y += (1 - INSTANT_ACCEL_COEF) * marbleSpeed.y * PERIOD_S + INSTANT_ACCEL_COEF * MAX_MARBLE_ACC * PERIOD_S * accel.y;
  return marblePosition;
}
void DrawBall(){
  for(int i= (int) marblePosition.x;i<=((int)marblePosition.x+3);i++){
    if(i==(int)marblePosition.x || i==(int)marblePosition.x+3){
      OrbitOledMoveTo(i,(int)marblePosition.y+1);
      OrbitOledDrawPixel();
      OrbitOledMoveTo(i,(int)marblePosition.y+2);
      OrbitOledDrawPixel();
    }
    else {
      OrbitOledMoveTo(i,(int)marblePosition.y);
      OrbitOledDrawPixel();
      OrbitOledMoveTo(i, (int)marblePosition.y+3);
      OrbitOledDrawPixel();
    }
  }
  OrbitOledUpdate();
}

/* ClearBall
*  Clears the last position of the marble by filling the positoins with a blank rectangle
*/
void ClearBall(){
  OrbitOledMoveTo((int)marblePosition.x + 1,(int) marblePosition.y);
  OrbitOledSetFillPattern(OrbitOledGetStdPattern(iptnBlank));
  OrbitOledSetDrawMode(modOledSet);
  OrbitOledFillRect((int) marblePosition.x + 2,(int) marblePosition.y + 3);
  OrbitOledMoveTo((int) marblePosition.x,(int) marblePosition.y + 1);
  OrbitOledFillRect((int) marblePosition.x + 3,(int) marblePosition.y + 2);
}

void MoveBall(){
  ClearBall();
  getAccel();
  GetSpeed();
  GetPosition();
  Serial.println(marblePosition.x);
  DrawBall();
}
