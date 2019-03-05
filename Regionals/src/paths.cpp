#include "main.h"

//Motion profiling
//Point{FORWARD, LEFT, CCLOCK}

void mainPathGen(){
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},  // Profile starting position, this will normally be (0, 0, 0)
    Point{38_in, 0_ft, 0_deg}}, // The next point in the profile, 3 feet forward
    "34" // Profile name
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{42_in, 0_in, 0_deg}},
    "42"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{10_in, 0_in, 0_deg}},
    "10"
  );
  driveProfile.generatePath({ // generate 28 inch path
    Point{0_ft, 0_ft, 0_deg},
    Point{20_in, 0_ft, 0_deg}},
    "28"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{18_in, 0_ft, 0_deg}},
    "18"
  );
}

void skillsPathGen(){
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{38_in, 0_ft, 0_deg}},
    "38"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{33_in, 0_ft, 0_deg}},
    "33"
  );
  driveProfile.generatePath({
    Point{0_ft, 0_ft, 0_deg},
    Point{60_in, 0_ft, 0_deg}}, // gen far path
    "far"
  );
}
