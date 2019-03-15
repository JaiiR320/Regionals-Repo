#include "main.h"

//robot properties
double max_vel = 41.8;
double bot_width = 11.75 / 2;
double targetAngle = 0;
//Controllers
Controller master = ControllerId::master;
Controller partner = ControllerId::partner;

Motor left_front = 2_rmtr;
Motor left_back = 1_rmtr;
Motor right_front = 4_mtr;
Motor right_back = 3_mtr;

Motor flywheel_mtr(6, false, AbstractMotor::gearset::blue);

Motor lift_mtr = 10_mtr;

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
  2.5, //max acceleration m/s/s (kailas 4) (me 14.2)
  5, //max jerk m/s/s/s (kailas 10) (me 1400)
	drive //chassis
);

//flywheel control
AsyncVelIntegratedController flywheel = AsyncControllerFactory::velIntegrated(flywheel_mtr);

//lift control
AsyncPosIntegratedController lift = AsyncControllerFactory::posIntegrated(lift_mtr);

void resetAngle(){
	gyroA.reset();
	targetAngle = 0;
}
void driveTurn(double degrees, int speed){ //NOT USED
	//41.8 in/s, 9.15 in for 90 deg turn,
	double arclength = 2 * 3.1415926 * bot_width * (degrees / 360);

	double dist = (arclength / 12.566) * 360;

	std::cout << "degrees: " << degrees << '\n';

	left_back.moveRelative(dist, speed);
	left_front.moveRelative(dist, speed);
	right_back.moveRelative(-dist, speed);
	right_front.moveRelative(-dist, speed);

	double ratio = double(speed) / 200.0;
	double time = (arclength / (41.8 * ratio)) * 1000;
	if (time < 0) {
		time *= -1;
	}

	pros::delay(int(time) + 75);

	drive.tank(0, 0);
}

void volt(double left, double right){
	left_front.moveVoltage(12000*left);
	left_back.moveVoltage(12000*left);
	right_front.moveVoltage(12000*right);
	right_back.moveVoltage(12000*right);
}

void vel(double left, double right){
	left_front.moveVelocity(left);
	left_back.moveVelocity(left);
	right_front.moveVelocity(right);
	right_back.moveVelocity(right);
}

void turn(double degrees, int speed){
	targetAngle += degrees;
	double target = targetAngle;
	int count = 0;

	double kp = 1.3;
	double error = 1;
	double out;
	double xtra = 1;
	bool run = true;
	volt(0, 0);
	while (fabs(error) >= .25 && run) {
		error = target - gyroA.get();
		if (error < 0) {
			xtra = -4;
		} else {
			xtra = 4;
		}
		vel((error*kp) + xtra, (-error*kp) + xtra);

		pros::delay(20);
	}
	volt(0, 0);
}

void dist(double inches, double speed){
	if (inches > 0) {
		inches -= 3;
	} else if (inches < 0) {
		inches += 3;
	}
	//41.8 in/s max velocity, 41.8 m/s^2 acceleration (1 sec to accel)
	const double velocity = 41.8;
	int hertz = 50; //cycles per second
	double power = 0;
	double accel = 1.5; //accel in 1.5 seconds
	int dir = 1;
	if (inches < 0) { //for setting negative speeds/distances
		dir = -1;
	}
	double cycles = hertz * (speed/accel); //
	double max = (hertz/(velocity*speed)) * (abs(inches) - (velocity * std::pow(cycles * 1/hertz, 2)));

	while (fabs(power) < speed) {
		power += accel/hertz;
		volt(dir*power, dir*power); //slew up
		pros::delay(1000/hertz);
	}
  power = speed;
	volt(dir*speed, dir*speed); //set speed to max

	for (int i = 0; i < max; i++) {
		pros::delay(1000/hertz); //delay until slew down
	}

	while (fabs(power) >= accel/50) {
		power -= accel/hertz;
		volt(dir*power, dir*power); //slew down
		pros::delay(1000/hertz);
	}
	volt(0, 0);
}

void driveDist(float dist, int speed){//NOT USED
  dist = ((dist / 12.566) * 360);
	left_front.moveRelative(dist, speed);
	left_back.moveRelative(dist, speed);
	right_front.moveRelative(dist, speed);
	right_back.moveRelative(dist, speed);
}

void driveArc(double radius, double exit_angle, int side, int max_speed){ //NOT USED
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
	flywheel_mtr.moveVelocity(speed);
}

void liftPos(int pos){
	if (pos == 2) {
		lift.setMaxVelocity(160);
		lift.setTarget(415);
	} else if (pos == 1) {
		lift.setMaxVelocity(85);
		lift.setTarget(170);
	} else if (pos == 0) {
		lift.setMaxVelocity(180);
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
