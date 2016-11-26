float Vx = 0.0;
float Vy = 0.0;
float xPos = 0.0;
float yPos = 0.0;
#include <math.h>

<<<<<<< .mine
||||||| .r2325
//float Ax,Ay;
float Vx_0=0,Vy_0=0;
float Vx;
float Vy;
float xPos,x_0=0;
float yPos , y_0=0;

=======
#define FRAME_TIME 0.04f
#define REBOUND_FACTR 0.2f
#define MAX_MARBLE_ACC 50

>>>>>>> .r2523
<<<<<<< .mine
void GetSpeed(){
  Vx += -1.0 * Ax / 9.8 * 32;
  Vy += 1.0 * Ay / 9.8 * 32;
 Serial.print("Vx: ");
 Serial.print(Vx);
 Serial.print(" ");
 Serial.print("Vy:");
 Serial.println(Vy);
 }
||||||| .r2325
void GetSpeed(){
  Vx=Ax*(1000.0/1000.0)+Vx_0;
  Vy=Ay*(1000.0/1000.0)+Vy_0;
  Vx_0=Vx;
  Vy_0=Vy;
 Serial.print("x:");
 Serial.print(Vx);
 Serial.print(" ");
 Serial.print("y:");
 Serial.println(Vy);
 }
=======
struct speed{
float x;
float y;
};
>>>>>>> .r2523

<<<<<<< .mine
void GetPos(){
  GetSpeed();
  xPos += Vx * (PERIOD_S);
  yPos += Vy * (PERIOD_S);
  Serial.print("Xpos: ");
||||||| .r2325
void GetPos(){
  GetSpeed();
  xPos=Vx*(10.0/1000.0)+x_0;
  yPos=Vy*(10.0/1000.0)+y_0;
  Serial.print("Xpos");
=======
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
>>>>>>> .r2523
  Serial.println(xPos);
  Serial.print("Ypos: ");
<<<<<<< .mine
  Serial.println(yPos);
||||||| .r2325
  Serial.println(yPos);
   
 
  x_0=xPos;
  y_0=yPos;
=======
  Serial.println(yPos);*/
  
>>>>>>> .r2523
}
void DrawBall(){
<<<<<<< .mine
  GetPos();
  OrbitOledClearBuffer();
  OrbitOledMoveTo(xPos,yPos);
  OrbitOledDrawPixel();
||||||| .r2325
  GetPos();
  OrbitOledMoveTo(-xPos,-yPos);
=======
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
>>>>>>> .r2523
  OrbitOledUpdate();
<<<<<<< .mine
  //pbOledCur+=xPos;
  //OrbitOledDrawPixel()
}
||||||| .r2325
  OrbitOledPutChar('o');
  
  
  
  //pbOledCur+=xPos;
  //OrbitOledDrawPixel()
}
=======
}

void MoveBall(){
  Move();
  GetSpeed();
  GetPosition();
  ClearBall();
  DrawBall();
  
 
}

>>>>>>> .r2523
