#include "main.h"

using namespace pros;

void frontPark(int side){ //16 swing, 10 total
  flySet(600);
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
  dist(32, .75); // flip cap

  turn(-90*side, 85);
  dist(50, 1);

  robotStop();

  while (1) {delay(20);}
}

void frontFlag(int side){ //13 swing, 8 total
  flySet(600);
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
  dist(20, .5);

  turn(45*side, 85); //turn to pole
  dist(46, .55);
  delay(150);

  resetAngle();
  delay(150);
  liftPos(2);
  delay(1700);
  dist(-12, .25); //put cap on pole
  liftPos(0);


  turn(-115*side, 85);
  index(200); //shoot middle flag
  delay(700);

  turn(-65*side, 85);
  dist(28, .85);
  turn(90*side, 85); //turn to platform
  dist(40, .85);
  robotStop();

  while(1){}
}


/*

SKILLS

*/

void skills(int side){//flags, caps, bottom flags, center park
  intake(200);
  dist(40, .80); //grab ball
  turn(45*side, 85);
  dist(-12, .85);
  turn(90*side, 85);

  dist(-12, .50); //grab cap
  intake(0);
  liftPos(1);
  delay(500);
  dist(20, .5);

  turn(45*side, 85); //turn to pole
  dist(46, .55);
  delay(150);
  resetAngle();
  delay(150);
  flySet(600);
  liftPos(2);
  delay(1700);
  dist(-12, .25); //put cap on pole
  liftPos(0);

  turn(-89*side, 85);
  dist(63, .85);

  intake(-2);
  index(200); // shoot
  delay(700);
  index(-1);
  delay(20);

  intake(200); // start pushing ball into indexer

  dist(18, .5);

  index(200); // 2nd shoot
  delay(950);
  index(0);
  flySet(520);

  turn(15 * side, 85);
  dist(16, .5); //turn into flags
  dist(-16, .5);
  turn(-15*side, 85);

  dist(-26, .85);
  turn(-90*side, 85); //turn to cap

  dist(40, .85); //get ball
  turn(90*side, 85);

  index(200); //shoot top flag
  delay(550);

  dist(24, .85);

  resetAngle();
  dist(-20, .85);
  turn(90*side, 85); //flip cap
  intake(-200);
  dist(32, .85);

  turn(90*side, 85);
  dist(28, .85);

  turn(90*side, 85);
  dist(65, .85);


  while (1) {delay(20);}
}
