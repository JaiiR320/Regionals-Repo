#include "main.h"

double bot_width = 11.75 / 2;

//Controllers
Controller master = ControllerId::master;
Controller partner = ControllerId::partner;

Motor left_front = 2_rmtr;
Motor left_back = 1_rmtr;
Motor right_front = 4_mtr;
Motor right_back = 3_mtr;

Motor flywheel_mtr = 6_mtr;

Motor lift_mtr = 10_rmtr;

Motor intake_mtr = 7_mtr;

Motor index_mtr = 9_mtr;

//drive train control
ChassisControllerIntegrated drive = ChassisControllerFactory::create(
	{left_front, left_back},
	{right_front, right_back},
	AbstractMotor::gearset::green,
	{4_in, 11.75_in}
);

//Motion profile
AsyncMotionProfileController driveProfile = AsyncControllerFactory::motionProfile(
	1.06, //Max Linear velocity m/s (calculated based off rpm of motor)
  4, //max acceleration m/s/s (kailas 4) (me 14.2)
  10, //max jerk m/s/s/s (kailas 10) (me 1400)
	drive //chassis
);

//flywheel control
AsyncVelIntegratedController flywheel = AsyncControllerFactory::velIntegrated(flywheel_mtr);

//lift control
AsyncPosIntegratedController lift = AsyncControllerFactory::posIntegrated(lift_mtr);

void driveTurn(int degrees, int side, int speed){ //Pos degrees turns right
	degrees *= side;

	thetaT += degrees; // sets global theoretical angle
	double arclength = 2 * 3.1415926 * bot_width * (double(degrees) / 360);

	double dist = (arclength / 12.566) * 360;

	std::cout << "degrees: " << degrees << '\n';

	left_back.moveRelative(dist, speed);
	left_front.moveRelative(dist, speed);
	right_back.moveRelative(-dist, speed);
	right_front.moveRelative(-dist, speed);

	//41.8 in/s, 9.15 in for 90 deg turn,

	double ratio = double(speed) / 200.0;
	double time = (arclength / (41.8 * ratio)) * 1000;
	if (time < 0) {
		time *= -1;
	}

	pros::delay(int(time + 50));

	bool running = true;
	double error;
	double out;

	if (dtheta > 0 && degrees < 0) {
		degrees *= -1;
	}

	while (running) {
		error = degrees - gyroA.get();
		out = error;

		left_front.moveVelocity(out);
		left_back.moveVelocity(out);
		right_front.moveVelocity(-out);
		right_back.moveVelocity(-out);

		if (left_front.getActualVelocity() == 0) {
			running = false;
		}

		std::cout << "error:   " << error << '\n';
		std::cout << "theta A: " << thetaA << '\n';
		std::cout << "gyro A:  " << gyroA.get() << '\n';
		std::cout << "degrees: " << degrees << '\n';

		pros::delay(50);
	}
	drive.tank(0, 0);
}

void driveDist(float dist, int speed){//in inches
  dist = ((dist / 12.566) * 360);
}

void driveArc(double radius, double exit_angle, int side, int max_speed){
	exit_angle *= 3.1415926 / 180.0; //1.5 for 90 deg
	//-40 rad =
  double arc_left = (radius + (side * 7.325)) * exit_angle;
  double arc_right = (radius + (side * -7.325)) * exit_angle;

	arc_left = (arc_left / 12.566) * 360;
	arc_right = (arc_right / 12.566) * 360;

	double Lspeed, Rspeed;

	if(abs(arc_left) > abs(arc_right)){
		Lspeed = max_speed;
		Rspeed = (arc_right / arc_left) * max_speed;
	} else if(abs(arc_left) > abs(arc_right)){
		Rspeed = max_speed;
		Lspeed = (arc_left / arc_right) * max_speed;
	}

	left_back.moveRelative(arc_left, Lspeed);
	left_front.moveRelative(arc_left, Lspeed);
	right_back.moveRelative(arc_right, Rspeed);
	right_front.moveRelative(arc_right, Rspeed);
}

void intake(int speed){
	intake_mtr.moveVelocity(speed);
}

void index(int speed){
	index_mtr.moveVelocity(speed);
}

void flySet(int speed){
	flywheel.setTarget(speed);
}

void liftPos(int pos){
	if (pos == 2) {
		lift.setTarget(900);
	} else if (pos == 1) {
		lift.setTarget(220);
	} else if (pos == 0) {
		lift.setTarget(0);
	}
}

//Stop entire robot
void robotStop () {
	drive.stop();
	intake_mtr.moveVelocity(0);
	index_mtr.moveVelocity(0);
	flywheel.setTarget(0);
}
