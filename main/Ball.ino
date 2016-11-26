#include <delay.h>
#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <math.h>

#define FRAME_TIME 0.04f
#define REBOUND_FACTR 0.2f
#define MAX_MARBLE_ACC 50

struct speed{
float x;
float y;
};

struct position{
  int x;
  int y;
};

struct position curPosition = (struct position){.x = 1, .y = 1};

struct speed curSpeed = (struct speed){0};
extern char    rgbOledBmp[];

/*Keep this for now
 * Roll angle:
double getRoll( float Ax, float Az){
  
  return atan(-Ax/Az)*(180/3.14);
}*/


struct speed GetSpeed(){
  if(curPosition.x > 124 || curPosition.x < 0 || curPosition.y > 28 || curPosition.y < 0){
    if(curPosition.x > 124 || curPosition.x < 0){
      curSpeed.x *= (fabs(curSpeed.x) < 1) ? 0 : -REBOUND_FACTR;
      curPosition.x = (curPosition.x >= 124) ? 124 : 0;
      if(curPosition.y > 28 || curPosition.y < 0){
        curSpeed.y *= (fabs(curSpeed.y) < 1) ? 0 : -REBOUND_FACTR;
        curPosition.y = (curPosition.y >= 28) ? 28 : 0;
      }
      else
        curSpeed.y += Ay * FRAME_TIME * MAX_MARBLE_ACC / 9.8;
    }  
    if(curPosition.y > 28 || curPosition.y < 0){
      curSpeed.y *= (fabs(curSpeed.y) < 1) ? 0 : -REBOUND_FACTR;
      curPosition.y = (curPosition.y >= 28) ? 28 : 0;
      if(curPosition.x > 124 || curPosition.x < 0){
        curSpeed.x *= (fabs(curSpeed.x) < 1) ? 0 : -REBOUND_FACTR;
        curPosition.x = (curPosition.x >= 124) ? 124 : 0;
      }
      else
        curSpeed.x -= Ax * FRAME_TIME * MAX_MARBLE_ACC;
    }
  }
    else{
  curSpeed.x -= Ax * FRAME_TIME * MAX_MARBLE_ACC;
  curSpeed.y += Ay*FRAME_TIME * MAX_MARBLE_ACC;
  }
  return curSpeed;
}
   
struct position GetPosition(){
  curPosition.x+=(int)((curSpeed.x)*FRAME_TIME);
  curPosition.y+=(int)((curSpeed.y)*FRAME_TIME);
  Serial.println(curPosition.x);
  
  /* Serial.print("Ax:");
  Serial.println(factor_x);
   Serial.print("   ");
  Serial.print("Ay:");
  Serial.println(factor_y);
   Serial.print("\n");*/
  return curPosition;
 /*Serial.print("Xpos");
  Serial.println(xPos);
  Serial.print("ypos");
  Serial.println(yPos);*/
  
}
void DrawBall(){
  OrbitOledClearBuffer();
  for(int i=curPosition.x;i<=(curPosition.x+3);i++){
    if(i==curPosition.x || i==curPosition.x+3){
        OrbitOledMoveTo(i,curPosition.y+1);
        OrbitOledDrawPixel();
        OrbitOledMoveTo(i,curPosition.y+2);
        OrbitOledDrawPixel();
    }else {
      OrbitOledMoveTo(i,curPosition.y);
      OrbitOledDrawPixel();
      OrbitOledMoveTo(i, curPosition.y+3);
      OrbitOledDrawPixel();
    }
  }
    OrbitOledUpdate();   
}

/* ClearBall
 *  Clears the last position of the marble by filling the positoins with a blank rectangle
 */
void ClearBall(){       
 
  OrbitOledMoveTo(curPosition.x+1,curPosition.y);
  OrbitOledSetFillPattern(OrbitOledGetStdPattern(iptnBlank));
  OrbitOledSetDrawMode(modOledSet);
  OrbitOledFillRect(curPosition.x+2,curPosition.y+3);
  OrbitOledMoveTo(curPosition.x,curPosition.y+1);
  OrbitOledFillRect(curPosition.x+3,curPosition.y+2);
  OrbitOledUpdate();
}

void MoveBall(){
  ClearBall();
  Move();
  GetSpeed();
  GetPosition();
  DrawBall();
}

