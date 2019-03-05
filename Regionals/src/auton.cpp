#include "main.h"

using namespace pros;

void mainAuton(int side){
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

  turn(90 * side, 85);
  dist(-50, 1);

  robotStop();

  while (1) {delay(20);}

}
void skillsAuton(int side){
  flySet(200);
  intake(200);
  dist(40, .80); //grab ball
  turn(45*side, 85);
  dist(-12, .85);
  turn(90*side, 85);
  driveDist(-10, 40); //grab cap

  liftPos(1);


  while (1) {delay(20);}
}

void backAuton(int side){

  turn(90.0 * side, 85);

  turn(-45.0 * side, 85);
  turn(-45 * side, 85);

  while(1){}
}

/*
//main Auton
void mainAuton(int side){
  mainPathGen();
  flySet(200);
  intake(200);

  driveProfile.setTarget("34");
  driveProfile.waitUntilSettled();
  drive.setMaxVelocity(175);
  driveProfile.setTarget("42", true);
  driveProfile.waitUntilSettled();
  drive.setMaxVelocity(200);

  driveTurn(90, side, 85);

  driveProfile.setTarget("10");
  driveProfile.waitUntilSettled();

  delay(500);
  intake(0);
  index(200); // shoot
  delay(700);
  index(-1);
  delay(20);

  intake(200); // start pushing ball into indexer

  driveProfile.setTarget("28");
  driveProfile.waitUntilSettled(); // aim middle

  index(200); // 2nd shoot
  delay(850);

  flySet(0); // stop shooting devices
  intake(0);
  index(0);

  driveProfile.removePath("34"); // remove old paths for memory
  driveProfile.removePath("42");
  driveProfile.removePath("10");

  driveTurn(14, side, 100);

  driveProfile.setTarget("18");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("18", true); // move into flag
  driveProfile.waitUntilSettled();

  driveTurn(-130, side, 100); // turn to okapa

  intake(-200);
  drive.setMaxVelocity(150);
  driveProfile.setTarget("28");
  driveProfile.waitUntilSettled();

  driveTurn(60, side, 100);
  driveDist(36, 200);
  delay(3000);

  robotStop();
  while (1) {}
}
*/

/*
  SKILLS
*/
/*
void skillsAuton(int side){
  skillsPathGen();

  flySet(200);
  intake(200);

  driveProfile.setTarget("38");
  driveProfile.waitUntilSettled(); // to cap
  delay(20);
  driveProfile.setTarget("33", true); // back up
  driveProfile.waitUntilSettled();

  drive.setMaxVelocity(200);
  driveTurn(89, side, 85); // turn
  delay(700);

  driveProfile.removePath("38");
  driveProfile.removePath("33");
  delay(700);

  drive.setMaxVelocity(150);
  driveProfile.setTarget("far");

  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{31_in, 0_ft, 0_deg}}, // gen far path
    "29"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{30_in, 0_ft, 0_deg}},
    "18"
  );

  driveProfile.waitUntilSettled(); // far
  delay(100);
  driveProfile.removePath("far"); //mem clear

  delay(1200);
  intake(0);
  index(200); // shoot
  delay(700);
  index(-1);
  delay(20);

  intake(200); // start pushing ball into indexer

  driveProfile.setTarget("29");
  driveProfile.waitUntilSettled(); // aim middle

  index(200); // 2nd shoot
  delay(750);

  intake(0); // stop shooting devices
  index(0);


  driveTurn(14, side, 100); // turn into flag
  delay(500);

  driveProfile.setTarget("18");
  driveProfile.waitUntilSettled();
  driveProfile.setTarget("18", true); // move into flag
  driveProfile.waitUntilSettled();

  driveTurn(-112, side, 100);
  delay(800);

  driveProfile.removePath("29");
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{60_in, 0_ft, 0_deg}},
    "50"
  );


  intake(-200);
  drive.setMaxVelocity(150);
  driveProfile.setTarget("50"); // flip cap
  driveProfile.removePath("18"); // remove 18
  driveProfile.waitUntilSettled(); // 50
  intake(0);

  driveProfile.removePath("50"); // remove 18

  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{31_in, 0_ft, 0_deg}},
    "21"
  );

  driveProfile.setTarget("21", true);
  driveProfile.waitUntilSettled();

  driveProfile.removePath("21");

  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{29_in, 0_ft, 0_deg}},
    "29"
  );

  driveTurn(-88, side, 100); // turn towards platform
  delay(800);

  driveProfile.setTarget("29");
  intake(200);

  driveProfile.waitUntilSettled();

  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{40_in, 0_ft, 0_deg}},
    "34"
  );

  driveTurn(85, side, 100); // turn towards cap
  delay(650);

  driveProfile.setTarget("34");
  delay(1700);
  intake(0);
  driveProfile.waitUntilSettled();

  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{12_in, 0_ft, 0_deg}},
    "6"
  );

  driveProfile.setTarget("6", true);
  driveProfile.waitUntilSettled();

  driveTurn(87, side, 100); // turn towards flags
  delay(650);

  driveProfile.removePath("6");

  driveProfile.setTarget("29");
  driveProfile.waitUntilSettled();

  index(200);
  intake(200);
  delay(1500);

  flySet(0);
  index(0);
  intake(0);

  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{27_in, 0_ft, 0_deg}},
    "24"
  );

  driveTurn(14, side, 100); // turn into flag
  delay(650);

  driveProfile.setTarget("24");
  driveProfile.waitUntilSettled(); // move into bottom flag

  driveTurn(-14, side, 100); // turn into flag
  delay(650);

  driveProfile.setTarget("24", true);
  driveProfile.waitUntilSettled(); // back up
  driveProfile.setTarget("24", true);
  driveProfile.waitUntilSettled(); // back up

  driveProfile.removePath("24");

  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{48_in, 0_ft, 0_deg}},
    "44"
  );

  driveTurn(-88, side, 100);
  delay(650);

  driveProfile.setTarget("44", true);
  driveProfile.waitUntilSettled(); // to wall

  driveProfile.removePath("44");
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{39_in, 0_ft, 0_deg}},
    "26"
  );

  driveTurn(-88, side, 100);
  delay(650);

  driveProfile.setTarget("26");
  driveProfile.waitUntilSettled();

  driveProfile.removePath("26");

  driveTurn(88, side, 100);
  delay(650);

  driveDist(82, 150);
  delay(3750);

  left_back.moveRelative(0, 0);
  left_front.moveRelative(0, 0);
  right_back.moveRelative(0, 0);
  right_front.moveRelative(0, 0);

  robotStop();

  while (1) {}
}
*/
