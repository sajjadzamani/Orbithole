/*Keep this for now
 * Roll angle:
double getRoll( float Ax, float Az){
  
  return atan(-Ax/Az)*(180/3.14);
}*/
double *GetSpeed(){
  if(marblePosition[0] > 124 || marblePosition[0] < 0 || marblePosition[1] > 28 || marblePosition[1] < 0){
    if(marblePosition[0] > 124 || marblePosition[0] < 0){
      marbleSpeed[0] *= (fabs(marbleSpeed[0]) < 1) ? 0 : -REBOUND_FACTR;
      marblePosition[0] = (marblePosition[0] >= 124) ? 124 : 0;
      if(marblePosition[1] > 28 || marblePosition[1] < 0){
        marbleSpeed[1] *= (fabs(marbleSpeed[1]) < 1) ? 0 : -REBOUND_FACTR;
        marblePosition[1] = (marblePosition[1] >= 28) ? 28 : 0;
      }
      else
        marbleSpeed[1] += Ay * PERIOD_S * MAX_MARBLE_ACC / 9.8;
    }  
    if(marblePosition[1] > 28 || marblePosition[1] < 0){
      marbleSpeed[1] *= (fabs(marbleSpeed[1]) < 1) ? 0 : -REBOUND_FACTR;
      marblePosition[1] = (marblePosition[1] >= 28) ? 28 : 0;
      if(marblePosition[0] > 124 || marblePosition[0] < 0){
        marbleSpeed[0] *= (fabs(marbleSpeed[0]) < 1) ? 0 : -REBOUND_FACTR;
        marblePosition[0] = (marblePosition[0] >= 124) ? 124 : 0;
      }
      else
        marbleSpeed[0] -= Ax * PERIOD_S * MAX_MARBLE_ACC;
    }
  }
    else{
  marbleSpeed[0] -= Ax * PERIOD_S * MAX_MARBLE_ACC;
  marbleSpeed[1] += Ay*PERIOD_S * MAX_MARBLE_ACC;
  }
  return marbleSpeed;
}
   
int *GetPosition(){
  marblePosition[0]+=(int)((marbleSpeed[0])*PERIOD_S);
  marblePosition[1]+=(int)((marbleSpeed[1])*PERIOD_S);
  Serial.println(marblePosition[0]);
    return marblePosition;
}
void DrawBall(){
  OrbitOledClearBuffer();
  for(int i=marblePosition[0];i<=(marblePosition[0]+3);i++){
    if(i==marblePosition[0] || i==marblePosition[0]+3){
        OrbitOledMoveTo(i,marblePosition[1]+1);
        OrbitOledDrawPixel();
        OrbitOledMoveTo(i,marblePosition[1]+2);
        OrbitOledDrawPixel();
    }else {
      OrbitOledMoveTo(i,marblePosition[1]);
      OrbitOledDrawPixel();
      OrbitOledMoveTo(i, marblePosition[1]+3);
      OrbitOledDrawPixel();
    }
  }
    OrbitOledUpdate();   
}

/* ClearBall
 *  Clears the last position of the marble by filling the positoins with a blank rectangle
 */
void ClearBall(){       
 
  OrbitOledMoveTo(marblePosition[0]+1,marblePosition[1]);
  OrbitOledSetFillPattern(OrbitOledGetStdPattern(iptnBlank));
  OrbitOledSetDrawMode(modOledSet);
  OrbitOledFillRect(marblePosition[0]+2,marblePosition[1]+3);
  OrbitOledMoveTo(marblePosition[0],marblePosition[1]+1);
  OrbitOledFillRect(marblePosition[0]+3,marblePosition[1]+2);
  OrbitOledUpdate();
}


void MoveBall(){
  Move();
  GetSpeed();
  GetPosition();
  ClearBall();
  DrawBall();
}
