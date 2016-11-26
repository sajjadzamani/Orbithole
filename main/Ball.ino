/*Keep this for now
 * Roll angle:
double getRoll( float Ax, float Az){

  return atan(-Ax/Az)*(180/3.14);
}*/
struct floatVector *GetSpeed(){
  if(marblePosition.x > 124 || marblePosition.x < 0 || marblePosition.y > 28 || marblePosition.y < 0){
    if(marblePosition.x > 124 || marblePosition.x < 0){
      marbleSpeed.x *= (fabs(marbleSpeed.x) < 1) ? 0 : -REBOUND_FACTR;
      marblePosition.x = (marblePosition.x >= 124) ? 124 : 0;
      if(marblePosition.y > 28 || marblePosition.y < 0){
        marbleSpeed.y *= (fabs(marbleSpeed.y) < 1) ? 0 : -REBOUND_FACTR;
        marblePosition.y = (marblePosition.y >= 28) ? 28 : 0;
      }
      else
        marbleSpeed.y += Ay * PERIOD_S * MAX_MARBLE_ACC / 9.8;
    }
    if(marblePosition.y > 28 || marblePosition.y < 0){
      marbleSpeed.y *= (fabs(marbleSpeed.y) < 1) ? 0 : -REBOUND_FACTR;
      marblePosition.y = (marblePosition.y >= 28) ? 28 : 0;
      if(marblePosition.x > 124 || marblePosition.x < 0){
        marbleSpeed.x *= (fabs(marbleSpeed.x) < 1) ? 0 : -REBOUND_FACTR;
        marblePosition.x = (marblePosition.x >= 124) ? 124 : 0;
      }
      else
        marbleSpeed.x -= Ax * PERIOD_S * MAX_MARBLE_ACC;
    }
  }
    else{
  marbleSpeed.x -= Ax * PERIOD_S * MAX_MARBLE_ACC;
  marbleSpeed.y += Ay*PERIOD_S * MAX_MARBLE_ACC;
  }
  return marbleSpeed;
}

struct intVector *GetPosition(){
  marblePosition.x+=(int)((marbleSpeed.x)*PERIOD_S);
  marblePosition.y+=(int)((marbleSpeed.y)*PERIOD_S);
  Serial.println(marblePosition.x);
    return marblePosition;
}
void DrawBall(){
  OrbitOledClearBuffer();
  for(int i=marblePosition.x;i<=(marblePosition.x+3);i++){
    if(i==marblePosition.x || i==marblePosition.x+3){
        OrbitOledMoveTo(i,marblePosition.y+1);
        OrbitOledDrawPixel();
        OrbitOledMoveTo(i,marblePosition.y+2);
        OrbitOledDrawPixel();
    }else {
      OrbitOledMoveTo(i,marblePosition.y);
      OrbitOledDrawPixel();
      OrbitOledMoveTo(i, marblePosition.y+3);
      OrbitOledDrawPixel();
    }
  }
    OrbitOledUpdate();
}

/* ClearBall
 *  Clears the last position of the marble by filling the positoins with a blank rectangle
 */
void ClearBall(){

  OrbitOledMoveTo(marblePosition.x+1,marblePosition.y);
  OrbitOledSetFillPattern(OrbitOledGetStdPattern(iptnBlank));
  OrbitOledSetDrawMode(modOledSet);
  OrbitOledFillRect(marblePosition.x+2,marblePosition.y+3);
  OrbitOledMoveTo(marblePosition.x,marblePosition.y+1);
  OrbitOledFillRect(marblePosition.x+3,marblePosition.y+2);
  OrbitOledUpdate();
}


void MoveBall(){
  Move();
  GetSpeed();
  GetPosition();
  ClearBall();
  DrawBall();
}
