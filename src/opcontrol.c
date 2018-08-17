#include "main.h"
#include "global.h"

#define versionnumber "2.1.8"
/*
NOTES:
implement constants and methods
*/
#define thresh 10

void driving(); //The function will read the left joystick's coordinates and will set the motor's speeds to match
void stopDriving();
void armspeed(int speed); //Takes in the speed the arm needs to move at and moves both motors at that speed
void clawRotateSpeed(int speed);
void clawSpeed(int speed); //opens and closes the claw at the right speed
void launch(); //The function will move the arm up and after a delay open the claw, "throwing" what ever was in the claw
void autooc(); //A shortcut to quickly open and close the claw
void forward(); //A set of pre configured motor speeds to drive forward
void backward(); //A set of pre configured motor speeds to drive backward
void right(); //A set of pre configured motor speeds to drive right
void left(); //A set of pre configured motor speeds to drive left
void auton(); //The code we plan to use for our auton
void randomnessCheck();

int xpos = 0;
int ypos = 0;
int xpos1 = 0;
int ypos1 = 0;
int xpos2 = 0;
int ypos2 = 0;
int OCcounter = 0;
int drivingMode = 0;

void operatorControl() {
  //Type pros terminal
  printf("Version #: %s\n\nTank_Drive_Code_2018_19_TLC\n\n\n",versionnumber);
  analogCalibrate(ARMLPOT);
  analogCalibrate(ARMRPOT);
  analogCalibrate(CLAWROTATEPOT);
  int loop = 0;
  while (1) {
    if(drivingMode == 0||drivingMode == 2){
      driving();
      loop++;
      if(loop>5000){
        printf("Arm L: %d, Arm R: %d, Claw Rotate: %d\n",analogReadCalibrated(ARMLPOT),analogReadCalibrated(ARMRPOT),analogReadCalibrated(CLAWROTATEPOT));
        loop=0;
      }
      //Arm controls
      if(joystickGetDigital(1,5,JOY_UP)||joystickGetDigital(2,5,JOY_UP)){
        clawRotateSpeed(-127);
      }else if(joystickGetDigital(1,5,JOY_DOWN)||joystickGetDigital(2,5,JOY_DOWN)){
        clawRotateSpeed(127);
      }else{
        clawRotateSpeed(0);
      }

      if(joystickGetAnalog(1,2)<-10 || 10<joystickGetAnalog(1,2)){ //The right joystick's Y coordinate can control the arm
        armspeed(joystickGetAnalog(1,2));
      }else if(joystickGetAnalog(2,2)<-10 || 10<joystickGetAnalog(2,2)){ //The right joystick's Y coordinate can control the arm
        armspeed(joystickGetAnalog(2,2));
      }else{
        armspeed(0);
      }

      //Claw controls
      if(joystickGetDigital(1,6,JOY_UP)||joystickGetDigital(2,6,JOY_UP)){
        clawSpeed(40);
      }else if(joystickGetDigital(1,6,JOY_DOWN)||joystickGetDigital(2,6,JOY_DOWN)){
        clawSpeed(-40);
      }else{
        clawSpeed(0);
      }

      //Short cut buttons
      if(joystickGetDigital(1,8,JOY_UP)||joystickGetDigital(2,8,JOY_UP)){
        launch(); //Idea to launch items
      }
      if(joystickGetDigital(1,8,JOY_LEFT)||joystickGetDigital(1,8,JOY_RIGHT)||joystickGetDigital(2,8,JOY_LEFT)||joystickGetDigital(2,8,JOY_RIGHT)){
        autooc(); //Auto open and close claw
      }

      if(joystickGetDigital(1,7,JOY_UP)){
        randomnessCheck();
      }

      if(joystickGetDigital(1,7,JOY_DOWN)&&joystickGetDigital(1,7,JOY_RIGHT)&&joystickGetDigital(1,7,JOY_LEFT)){
        //drivingMode = 1;
        auton();
      }
      while(joystickGetDigital(1,7,JOY_DOWN)&&joystickGetDigital(1,7,JOY_RIGHT)&&joystickGetDigital(1,7,JOY_LEFT)){}

    }else if(drivingMode == 1){
      motorSet(TL, joystickGetAnalog(1, 3));
      motorSet(BL, joystickGetAnalog(1, 3));
      motorSet(TR, -1*joystickGetAnalog(1, 2));
      motorSet(BR, -1*joystickGetAnalog(1, 2));

      if(joystickGetDigital(1, 5, JOY_UP)||joystickGetDigital(1, 6, JOY_UP)){
        armspeed(127);
      }else if(joystickGetDigital(1, 5, JOY_DOWN)||joystickGetDigital(1, 6, JOY_DOWN)){
        armspeed(-127);
      }else{
        armspeed(0);
      }

      if (joystickGetDigital(1, 7, JOY_RIGHT)||joystickGetDigital(1, 8, JOY_LEFT)) {
        clawSpeed(127);
      }else if (joystickGetDigital(1, 8, JOY_RIGHT)||joystickGetDigital(1, 7, JOY_LEFT)) {
        clawSpeed(-127);
      }else{
        clawSpeed(0);
      }

      if(joystickGetDigital(1,7,JOY_UP)){
        randomnessCheck();
      }

      if(joystickGetDigital(1,7,JOY_DOWN)&&joystickGetDigital(1,7,JOY_RIGHT)&&joystickGetDigital(1,7,JOY_LEFT)){
        drivingMode = 0;
      }
      while(joystickGetDigital(1,7,JOY_DOWN)&&joystickGetDigital(1,7,JOY_RIGHT)&&joystickGetDigital(1,7,JOY_LEFT)){}
    }else if(drivingMode == 3){
      if (joystickGetDigital(1, 7, JOY_UP)){
        motorSet(TL, 127);
      }else if (joystickGetDigital(1, 7, JOY_RIGHT)){
        motorSet(TL, -127);
      }else{
        motorSet(TL, 0);
      }
      if (joystickGetDigital(1, 7, JOY_LEFT)){
        motorSet(BL, 127);
      }else if (joystickGetDigital(1, 7, JOY_DOWN)){
        motorSet(BL, -127);
      }else{
        motorSet(BL, 0);
      }
      if (joystickGetDigital(1, 8, JOY_UP)){
        motorSet(TR, -127);
      }else if (joystickGetDigital(1, 8, JOY_LEFT)){
        motorSet(TR, 127);
      }else{
        motorSet(TR, 0);
      }
      if (joystickGetDigital(1, 8, JOY_RIGHT)){
        motorSet(BR, -127);
      }else if (joystickGetDigital(1, 8, JOY_DOWN)){
        motorSet(BR, 127);
      }else{
        motorSet(BR, 0);
      }


      if (joystickGetDigital(1, 5, JOY_UP)){
        motorSet(ARML, 127);
      }else if (joystickGetDigital(1, 5, JOY_DOWN)){
        motorSet(ARML, -127);
      }else{
        motorSet(ARML, 0);
      }
      if (joystickGetDigital(1, 6, JOY_UP)){
        motorSet(ARMR, -127);
      }else if (joystickGetDigital(1, 6, JOY_DOWN)){
        motorSet(ARMR, 127);
      }else{
        motorSet(ARMR, 0);
      }
      if (joystickGetAnalog(1, 3)>20){
        motorSet(ARML, 127);
      }else if (joystickGetAnalog(1, 3)<-20){
        motorSet(ARML, -127);
      }else{
        motorSet(ARML, 0);
      }
      if (joystickGetAnalog(1, 2)>20){
        motorSet(ARMR, -127);
      }else if (joystickGetAnalog(1, 2)<-20){
        motorSet(ARMR, 127);
      }else{
        motorSet(ARMR, 0);
      }


      if (joystickGetAnalog(1, 4)>20){
        motorSet(CLAW, -127);
      }else if (joystickGetAnalog(1, 4)<-20){
        motorSet(CLAW, 127);
      }else{
        motorSet(CLAW, 0);
      }
      if (joystickGetAnalog(1, 1)>20){
        motorSet(CLAW, -127);
      }else if (joystickGetAnalog(1, 1)<-20){
        motorSet(CLAW, 127);
      }else{
        motorSet(CLAW, 0);
      }
      if((joystickGetDigital(1, 7, JOY_UP)&&joystickGetDigital(1, 7, JOY_DOWN))||(joystickGetDigital(1, 8, JOY_UP)&&joystickGetDigital(1, 8, JOY_DOWN))){
        drivingMode=0;
      }
      while((joystickGetDigital(1, 7, JOY_UP)&&joystickGetDigital(1, 7, JOY_DOWN))||(joystickGetDigital(1, 8, JOY_UP)&&joystickGetDigital(1, 8, JOY_DOWN))){}
    }
    if((joystickGetDigital(2, 7, JOY_UP) || joystickGetDigital(2, 8, JOY_UP)) && (joystickGetDigital(1, 7, JOY_UP) || joystickGetDigital(1, 8, JOY_UP))){
      drivingMode = 2;
    }
  }
}


//Functions:

//run motors based on the direction of the joystick
void driving(){
  //Get the X and Y coordinates from the controller
  if(drivingMode == 0){
    xpos = joystickGetAnalog(1, 4);
    ypos = joystickGetAnalog(1, 3);
    if(joystickGetAnalog(1, 1) < -thresh || thresh < joystickGetAnalog(1, 1))
      xpos = joystickGetAnalog(1, 1);
    //powers motors at correct speeds
    if(!(ypos < -thresh || thresh < ypos || xpos < -thresh || thresh < xpos)){
      ypos=0;
      xpos=0;
    }
  }else{
    xpos1 = joystickGetAnalog(1, 1);
    ypos1 = joystickGetAnalog(1, 3);
    xpos2 = joystickGetAnalog(2, 1);
    ypos2 = joystickGetAnalog(2, 3);
    if(xpos1 < -thresh || thresh < xpos1){
      xpos = xpos1;
    }else if(xpos2 < -thresh || thresh < xpos2){
      xpos = xpos2;
    }else{
      xpos = 0;
    }
    if(ypos1 < -thresh || thresh < ypos1){
      ypos = ypos1;
    }else if(ypos2 < -thresh || thresh < ypos2){
      ypos = ypos2;
    }else{
      ypos = 0;
    }
  }
  /*if(ypos >= -thresh){*/
    xpos = xpos * -1;
  /*}*/
  motorSet(BL, (ypos-xpos));
  motorSet(TL, (ypos-xpos));
  motorSet(TR, -1 * (ypos+xpos));
  motorSet(BR, -1 * (ypos+xpos));
}
/*
void stopDriving(){
    motorSet(BL, 0);
    motorSet(TL, 0);
    motorSet(TR, 0);
    motorSet(BR, 0);
}
*/

void armspeed(int speed){//+speed = up
  //motorSet(ARMBL, -1 * speed);
  motorSet(ARML, speed);
  //motorSet(ARMACTUALR, speed);
  motorSet(ARMR, -1 * speed);
}

void clawRotateSpeed(int speed){//+speed = up
  //motorSet(ARMBL, -1 * speed);
  //motorSet(MGL, -1 * speed);
  //motorSet(ARMBR, speed);
  motorSet(CLAWROTATE, speed);
}

void clawSpeed(int speed){//+speed=close //RI = rakesh intake
  motorSet(CLAW,speed);
}

void launch(){
  armspeed(70);
  delay(500);
  clawSpeed(127);
  delay(500);
  clawSpeed(0);
  armspeed(0);
}

void autooc(){
  if(OCcounter%2==0){
    armspeed(127);
    delay(1500);
    armspeed(0);
  }else{
    armspeed(-127);
    delay(1500);
    armspeed(0);
  }
  OCcounter++;
}
/*
void forward(){
  motorSet(TL, 127);
  motorSet(BL, 127);
  motorSet(TR, -127);
  motorSet(BR, -127);
}
void backward(){
  motorSet(TL, -127);
  motorSet(BL, -127);
  motorSet(TR, 127);
  motorSet(BR, 127);
}
void right(){
  motorSet(TL, 127);
  motorSet(BL, 127);
  motorSet(TR, 127);
  motorSet(BR, 127);
}
void left(){
  motorSet(TL, -127);
  motorSet(BL, -127);
  motorSet(TR, -127);
  motorSet(BR, -127);
}
*/
void auton(){

}

void randomness(){
    drivingMode = 3;
  /*
  //TESTING MOTORS
  while(1==1){
      right();
      delay(15000);
      left();
      delay(5000);
      forward();
      delay(5000);
      right();
      backward();
      delay(5000);
      left();
      delay(5000);
      forward();
      delay(5000);
      backward();
      delay(5000);
      forward();
      delay(5000);
      backward();
      delay(5000);
      forward();
      delay(5000);
      backward();
      delay(5000);
      left();
      delay(5000);
      right();
      delay(5000);
      left();
      delay(5000);
      right();
      delay(5000);
  }
  */
}

int randomnessChecker(int direction){//1=up;2=down;3=left;4=right;
  if(direction == 1){
    if(joystickGetDigital(1,7,JOY_UP)){
      return 1;
    }
  }else if(direction == 2){
    if(joystickGetDigital(1,7,JOY_DOWN)){
      return 1;
    }
  }else if(direction == 3){
    if(joystickGetDigital(1,7,JOY_LEFT)){
      return 1;
    }
  }else if(direction == 4){
    if(joystickGetDigital(1,7,JOY_RIGHT)){
      return 1;
    }
  }
  if(joystickGetDigital(1,7,JOY_UP)||joystickGetDigital(1,7,JOY_DOWN)||joystickGetDigital(1,7,JOY_LEFT)||joystickGetDigital(1,7,JOY_RIGHT)){
    return 2;
  }
  return 0;//1=correct;2=wrong;0=null
}

void randomnessCheck(){
  while(randomnessChecker(1) == 1){}
  int time = 0;
  while(randomnessChecker(1) == 0 && time < 3000){
    time++;
    delay(1);
  }
  if(randomnessChecker(1) == 1){

    while(randomnessChecker(1) == 1){}
    while(randomnessChecker(2) == 0){}
    if(randomnessChecker(2) == 1){

      while(randomnessChecker(2) == 1){}
      while(randomnessChecker(2) == 0){}
      if(randomnessChecker(2) == 1){

        while(randomnessChecker(2) == 1){}
        while(randomnessChecker(3) == 0){}
        if(randomnessChecker(3) == 1){

          while(randomnessChecker(3) == 1){}
          while(randomnessChecker(4) == 0){}
          if(randomnessChecker(4) == 1){

            while(randomnessChecker(4) == 1){}
            while(randomnessChecker(3) == 0){}
            if(randomnessChecker(3) == 1){

              while(randomnessChecker(3) == 1){}
              while(randomnessChecker(4) == 0){}
              if(randomnessChecker(4) == 1){
                randomness();
              }
            }
          }
        }
      }
    }
  }
  /*right();
  delay(1000);
  if(joystickGetDigital(1,7,JOY_UP)){
      left();
      delay(1000);
      if(joystickGetDigital(1,7,JOY_DOWN)){
          right();
          delay(1000);
          if(joystickGetDigital(1,7,JOY_DOWN)){
              left();
              delay(1000);
              if(joystickGetDigital(1,7,JOY_LEFT)){
                  right();
                  delay(1000);
                  if(joystickGetDigital(1,7,JOY_RIGHT)){
                      left();
                      delay(1000);
                      if(joystickGetDigital(1,7,JOY_LEFT)){
                          right();
                          delay(1000);
                          if(joystickGetDigital(1,7,JOY_RIGHT)){
                              left();
                              delay(1000);
                              randomness();
                          }
                      }
                  }
              }
          }
      }
  }*/
}
