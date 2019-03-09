#include "main.h"

ADIGyro gyroA(7, .1);
/*
double gyroAngle = 0;
double encAngle = 0;
double actualAngle = 0; //actual angle of the robot
double expectedAngle = 0; //angle the bot should be at
double leftD, rightD = 0; //distance the robot travels per side
int dir = 1;

double trackError = 0;

void update(void* params){
  while (1) {
    leftD = left_back.getPosition();
    rightD = right_back.getPosition();

    leftD = (leftD/360) * 12.56; //calcs the distance wheels travel in in
    rightD = (rightD/360) * 12.56;

    encAngle = ((leftD+rightD)/36.9) * 360; //calcs encoder angle of the bot

    trackError = expectedAngle - encAngle;

    pros::delay(20);
  }
}

pros::Task tracking(update);
*/
