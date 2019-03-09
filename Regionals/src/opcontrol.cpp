#include "main.h"
void opcontrol() {
	float u, d;
	lift.tarePosition();

	//1 controller
	while (1) {
		while (duo == false){
			std::cout << "Gryo: " << gyroA.get() << '\n';

			u = master.getAnalog(ControllerAnalog::leftY);
			d = master.getAnalog(ControllerAnalog::rightY);

			drive.tank(u, d);

			//macros
			while(master.getDigital(ControllerDigital::down) == true){
				left_back.moveRelative(0, 0);
				left_front.moveRelative(0, 0);
				right_back.moveRelative(0, 0);
				right_front.moveRelative(0, 0);
			}

			//flywheel
			if (master.getDigital(ControllerDigital::Y) == true) {
				flySet(600);
			} else if (master.getDigital(ControllerDigital::B) == true) {
				flySet(0);
			}
			//doubleshot
			if (master.getDigital(ControllerDigital::up) == true){
				index(200);
				pros::delay(650);
				index(-1);
				intake(200);
				dist(26, .5);
				index(200);
			}

			//intake
			if (master.getDigital(ControllerDigital::L1) == true) {
				intake_mtr.moveVelocity(200);
			} else if (master.getDigital(ControllerDigital::L2) == true) {
				intake_mtr.moveVelocity(-200);
			} else {
				intake_mtr.moveVelocity(0);
			}

			//index
			if (master.getDigital(ControllerDigital::X) == true) {
				index_mtr.moveVelocity(200);
			} else if (master.getDigital(ControllerDigital::A) == true) {
				index_mtr.moveVelocity(-200);
			} else {
				index_mtr.moveVelocity(0);
			}

			//lift
			if (master.getDigital(ControllerDigital::R1) == true) {
				lift.setMaxVelocity(150);
				lift.setTarget(415);
			} else if (master.getDigital(ControllerDigital::R2) == true) {
				lift.setMaxVelocity(85);
				lift.setTarget(170);
			} else {
				lift.setMaxVelocity(180);
				lift.setTarget(0);
			}

			pros::delay(20);
		}

		/*
		DUAL DRIVER
		*/

		while (duo == true) {
			//Drive - WIP
			u = partner.getAnalog(ControllerAnalog::leftY);
			d = partner.getAnalog(ControllerAnalog::rightY);

			drive.tank(u * .9, d * .9);

			//stop
			while(partner.getDigital(ControllerDigital::R2) == true){
				left_back.moveRelative(0, 0);
				left_front.moveRelative(0, 0);
				right_back.moveRelative(0, 0);
				right_front.moveRelative(0, 0);
		  }

			//flywheel
			if (master.getDigital(ControllerDigital::Y) == true) {
				flywheel.setTarget(200);
			} else if (master.getDigital(ControllerDigital::B) == true) {
				flywheel.setTarget(0);
			}
			if (master.getDigital(ControllerDigital::up) == true){
				flywheel.setTarget(140);
			}

			//intake
			if (master.getDigital(ControllerDigital::L1) == true) {
				intake_mtr.moveVelocity(200);
			} else if (master.getDigital(ControllerDigital::L2) == true) {
				intake_mtr.moveVelocity(-200);
			} else {
				intake_mtr.moveVelocity(0);
			}

			//index
			if (master.getDigital(ControllerDigital::X) == true) {
				index_mtr.moveVelocity(200);
			} else if (master.getDigital(ControllerDigital::A) == true) {
				index_mtr.moveVelocity(-200);
			} else {
				index_mtr.moveVelocity(0);
			}

			//lift Position
			if (master.getDigital(ControllerDigital::R1) == true) {
				lift.setMaxVelocity(160);
				lift.setTarget(415);
			} else if (master.getDigital(ControllerDigital::R2) == true) {
				lift.setMaxVelocity(85);
				lift.setTarget(170);
			} else {
				lift.setMaxVelocity(180);
				lift.setTarget(0);
			}

			pros::delay(20);
		}
	}
}
