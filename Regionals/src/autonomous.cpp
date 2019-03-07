#include "main.h"


void autonomous() {

  switch (Aauton) {
    case 1: frontPark(Acolor);
    case 2: frontFlag(Acolor);
    case 3: backPark(Acolor);
    case 4: skills(Acolor);
  }
  pros::delay(99999);
}
