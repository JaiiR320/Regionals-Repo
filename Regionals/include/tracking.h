#ifndef TRACKING_H
#define TRACKING_H

#include "okapi/api.hpp"
#include "api.h"

using namespace okapi;

extern double gyroAngle;
extern double encAngle;
extern double actualAngle; //actual angle of the robot
extern double expectedAngle; //angle the bot should be at
extern double leftD, rightD; //distance the robot travels per side
extern int dir;

extern double trackError;

extern pros::task_fn_t update(void);
extern pros::Task tracking;

#endif
