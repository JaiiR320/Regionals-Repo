#include "main.h"

using namespace pros;

void frontPark(int side){ //16 swing, 10 total
  flySet(200);
  intake(200);

  dist(34, .75);
  dist(-30, .75);
  intake(0);

  turn(90*side, 85);

  delay(500);
  intake(-2);
  index(200); // shoot
  delay(700);
  index(-1);
  delay(20);

  intake(200); // start pushing ball into indexer

  dist(26, .5);

  index(200); // 2nd shoot
  delay(950);

  flySet(0); // stop shooting devices
  intake(0);
  index(0);

  turn(30 * side, 85);
  dist(18, .5);
  dist(-18, .5);

  turn(-120 * side, 85); // turn into cap

  intake(-200);
  dist(24, .75); // flip cap

  turn(-90*side, 85);
  dist(50, 1);

  robotStop();

  while (1) {delay(20);}
}

void frontFlag(int side){ //13 swing, 8 total
  flySet(200);
  intake(200);

  dist(34, .75);
  dist(-30, .75);
  intake(0);

  turn(90*side, 85);

  delay(500);
  intake(-2);
  index(200); // shoot
  delay(700);
  index(-1);
  delay(20);

  intake(200); // start pushing ball into indexer

  dist(26, .5);

  index(200); // 2nd shoot
  delay(950);

  flySet(0); // stop shooting devices
  intake(0);
  index(0);

  turn(30 * side, 85);
  dist(18, .5);
  dist(-18, .5);

  turn(-120 * side, 85); // turn into cap

  intake(-200);
  dist(24, .75); // flip cap

  turn(45*side, 85);
  dist(36, 1);

  robotStop();

  while (1) {delay(20);}
}

void backPark(int side){//7 swing, 6 total
  flySet(500);
  intake(200);
  dist(40, .80); //grab ball
  turn(45*side, 85);
  dist(-12, .85);
  turn(90*side, 85);

  dist(-12, .50); //grab cap
  intake(0);
  liftPos(1);
  delay(500);
  dist(18, .5);

  turn(45*side, 85); //turn to pole
  dist(48, .65);
  resetAngle();
  liftPos(2);
  delay(1800);
  dist(-12, .25); //put cap on pole
  liftPos(0);

  turn(-115*side, 85);
  index(200); //shoot middle flag
  delay(700);

  turn(-65*side, 85);
  dist(28, .85);
  turn(90*side, 85); //turn ot platform
  dist(40, .85);
  robotStop();

  while(1){}
}

void skills(int side){//flags, caps, bottom flags, center park
  flySet(200);
  intake(200);
  dist(40, .80); //grab ball
  turn(45*side, 85);
  dist(-12, .85);
  turn(90*side, 85);
  driveDist(-10, 40); //grab cap

  liftPos(1);
  driveDist(10, 40);
  turn(45*side, 85); //turn to pole
  dist(20, .75);
  liftPos(2);
  delay(1500);
  liftPos(0);
  driveDist(-10, 50); //put cap on pole

  turn(-90, 85);
  dist(60, .75);

  index(200);
  delay(700);


  while (1) {delay(20);}
}
