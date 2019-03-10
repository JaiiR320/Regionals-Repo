#include "main.h"

ADIGyro gyroA(7, .1);
/*
double gyroAngle = 0;
double dTheta = 0;
double actualAngle = 0; //actual angle of the robot
double expectedAngle = 0; //angle the bot should be at
double leftD, rightD = 0; //distance the robot travels per side
double prevL, prevR = 0;
int dir = 1;

double trackError = 0;

void update(void* params){
  while (1) {
    leftD = left_back.getPosition();
    rightD = right_back.getPosition();

    dTheta = ((leftD - prevL) - (rightD - prevR)) / 11.75;

    prevL = leftD;
    prevR = rightD;

    pros::delay(20);
  }
}

pros::Task tracking(update);
*/
