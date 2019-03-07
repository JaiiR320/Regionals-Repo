#ifndef AUTON_H
#define AUTON_H

#include "okapi/api.hpp"
using namespace okapi;

extern int Aauton;
extern int Acolor;
extern bool duo;

void frontPark(int side);
void frontFlag(int side);
void backPark(int side);
void skills(int side);

#endif
