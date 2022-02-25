#include "main.h"
#include <fstream>
#include <iostream>


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);


}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	// int target;
	//
	// PIDController drivePID =  PIDController(0.15, 0, 0.1);
	// PIDController turnPID =  PIDController(0.5, 0, 0.1);
	//
	// Drivetrain drive = Drivetrain();
	// const double TICKS_TO_INCHES = (2.75*M_PI)/360;
	//
 	// pros::ADIEncoder rightEncoder('C', 'D', true);
	// pros::Motor armMotor(16);
	//
	// armMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	//
	// target = 60;
	//
	// rightEncoder.reset();
	//
	//
	//
	//
	// while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target){
	// 	// int power = drivePID.updatePID(rightEncoder.get_value() * TICKS_TO_INCHES, -target);
	// 	// if(power < -127)
	// 	// {
	// 	// 	power = -127;
	// 	// }
	// 	//master.print(2,2,"%d", power);
	// 	drive.runRightDrive(115);
	// 	drive.runLeftDrive(115);
	// }
	// drive.setBrake();
	// drive.runRightDrive(0);
	// drive.runLeftDrive(0);
	// pros::delay(25);
	//
	// // armMotor.tare_position();
	// // while(armMotor.get_position() > -1800)
	// // {
	// // 	armMotor.move_velocity(-90);
	// // 	pros::delay(25);
	// // }
	// // armMotor.move_velocity(0);
	//
	// target = 30;
	//
	// rightEncoder.reset();
	//
	//
	//
	//
	// while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target){
	// 	// int power = drivePID.updatePID(rightEncoder.get_value() * TICKS_TO_INCHES, -target);
	// 	// if(power < -127)
	// 	// {
	// 	// 	power = -127;
	// 	// }
	// 	//master.print(2,2,"%d", power);
	// 	drive.runRightDrive(50);
	// 	drive.runLeftDrive(50);
	// }
	// drive.setBrake();
	// drive.runRightDrive(0);
	// drive.runLeftDrive(0);
	// pros::delay(25);
	//
	// target = 15;
	//
	// rightEncoder.reset();
	//
	//
	//
	//
	// while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target){
	// 	// int power = drivePID.updatePID(rightEncoder.get_value() * TICKS_TO_INCHES, -target);
	// 	// if(power < -127)
	// 	// {
	// 	// 	power = -127;
	// 	// }
	// 	//master.print(2,2,"%d", power);
	// 	drive.runRightDrive(-50);
	// 	drive.runLeftDrive(-50);
	// }
	// drive.setBrake();
	// drive.runRightDrive(0);
	// drive.runLeftDrive(0);
	// pros::delay(25);
	//
	// // rightEncoder.reset();
	// //
	// // target = 6;
	// //
	// // while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target){
	// // 	//int power = drivePID.updatePID(rightEncoder.get_value() * TICKS_TO_INCHES, target) * 100;
	// //
	// // 	drive.runRightDrive(50);
	// // 	drive.runLeftDrive(50);
	// // }
	// // drive.runRightDrive(0);
	// // drive.runLeftDrive(0);
	// // pros::delay(100);
	// //
	// // rightEncoder.reset();
	// //
	// // target = 3;
	// //
	// // while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target){
	// // 	// int power = turnPID.updatePID(rightEncoder.get_value(), -target) * 100;
	// // 	// master.print(2,2,"%d", power);
	// // 	// drive.runRightDrive(-power);
	// // 	// drive.runLeftDrive(power);
	// //
	// // 	drive.runRightDrive(50);
	// // 	drive.runLeftDrive(-50);
	// // }
	// // drive.runRightDrive(0);
	// // drive.runLeftDrive(0);
	// // pros::delay(50);
	// //
	// // rightEncoder.reset();
	// //
	// // target = 24.5;
	// //
	// // while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target - 0.5){
	// // 	int power = drivePID.updatePID(rightEncoder.get_value() * TICKS_TO_INCHES, -target) * 70;
	// // 	if(power < -127)
	// // 	{
	// // 		power = -127;
	// // 	}
	// // 	drive.runRightDrive(power);
	// // 	drive.runLeftDrive(power);
	// // }
	// // drive.runRightDrive(0);
	// // drive.runLeftDrive(0);
	// // pros::delay(100);
	// //
	// // rightEncoder.reset();
	// //
	// // target = 3;
	// //
	// // while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target){
	// // 	// int power = turnPID.updatePID(rightEncoder.get_value(), -target) * 100;
	// // 	// master.print(2,2,"%d", power);
	// // 	// drive.runRightDrive(-power);
	// // 	// drive.runLeftDrive(power);
	// //
	// // 	drive.runRightDrive(-50);
	// // 	drive.runLeftDrive(50);
	// // }
	// // drive.runRightDrive(0);
	// // drive.runLeftDrive(0);
	// // pros::delay(50);


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

}
void opcontrol() {
// 	pros::Controller master(CONTROLLER_MASTER);
// 	Arm *arm = new Arm();
// 	armMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
// 	armMotor.tare_position();
// 	while(true){
// 	if(master.get_digital_new_press(DIGITAL_R1)){
// 		armMotor.move_relative(-3000, 100);
// 	}
//
// 	if(master.get_digital_new_press(DIGITAL_L1)){
// 		armMotor.move_relative(-5000, 100);
//
// 	}
// }



	pros::Controller master(CONTROLLER_MASTER);
	pros::Controller partner(CONTROLLER_PARTNER);

	pros::ADIDigitalOut piston('A');
	pros::ADIDigitalOut secondary('B');

	pros::ADIEncoder rightEncoder('C', 'D', true);

	pros::Motor rightBack(6, true);
	pros::Motor rightFront(11, true);
	pros::Motor leftFront(4);
	pros::Motor leftBack(17);

	pros::Motor spinner(20);

	pros::Motor outtake(1);

	pros::Motor arm(10);

	pros::Motor intake(9);

	outtake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	int piston_state = 0;
	int secondary_state = 0;

	int intake_state = 0;

	const double TICKS_TO_INCHES = (2.75*M_PI)/360;

	rightEncoder.reset();

	while (true) {

		bool piston_button = partner.get_digital_new_press(DIGITAL_B);
		bool secondary_butn = partner.get_digital_new_press(DIGITAL_RIGHT);
		bool intake_button = partner.get_digital_new_press(DIGITAL_UP);

		bool outtake_button = partner.get_digital_new_press(DIGITAL_DOWN);
		bool intake_stop = partner.get_digital_new_press(DIGITAL_LEFT);

		//Drive Control
		int power = master.get_analog(ANALOG_RIGHT_Y);
		int turn = master.get_analog(ANALOG_LEFT_X);

		int right = power - turn;
		int left = power + turn;

		if(master.get_digital(DIGITAL_R1)){
			rightFront.move(right*0.5);
			rightBack.move(right*0.5);
			leftFront.move(left*0.5);
			leftBack.move(left*0.5);
		}else{
			rightFront.move(right);
			rightBack.move(right);
			leftFront.move(left);
			leftBack.move(left);
		}


		//Arm Control
		if (partner.get_digital(DIGITAL_R1)) {
			arm.move_velocity(100);
		}
		else if (partner.get_digital(DIGITAL_R2)) {
			arm.move_velocity(-100);
		}
		else {
			arm.move_velocity(0);
		}

		//Piston Control
		if(piston_button && piston_state % 2 == 0) {
			piston.set_value(true);
			piston_state++;
		}

		else if(piston_button && piston_state % 2 != 0) {
			piston.set_value(false);
			piston_state++;
		}

		//Stick Control
		if (partner.get_digital(DIGITAL_L2)) {
			outtake.move_velocity(20);
		}
		else if (partner.get_digital(DIGITAL_L1)) {
			outtake.move_velocity(-20);
		}
		else {
			outtake.move_velocity(0);
		}


		// if(spinBtn){
		// 	if((distance > min && distance < max) && (distance2 > min + 5 && distance2 < max + 5) ){
		// 		spinner.move(0);
		// 		master.print(2,2, "%d %d ", (distance), distance2);
		// 		break;
		// 	}
		// 	else{
		// 		spinner.move(50);
		// 	}
		// 	spinBtn = false;
		// }


		//Stick/outtake Controller
		if (partner.get_digital(DIGITAL_Y)) {
			spinner.move_velocity(100);
		}
		else if (partner.get_digital(DIGITAL_A)) {
			spinner.move_velocity(-100);
		}
		else if (master.get_digital(DIGITAL_A)) {
			spinner.move_velocity(-100);
		}
		else if (master.get_digital(DIGITAL_Y)) {
			spinner.move_velocity(100);
		}
		else {
			spinner.move_velocity(0);
		}

		if(intake_button) {
			intake.move(128);
		}
		else if(outtake_button) {
			intake.move(-129);
		}
		else if(intake_stop){
			intake.move(0);
		}

	}


	// pros::Controller master(pros::E_CONTROLLER_MASTER);
	//
	// Drivetrain drive = Drivetrain();
	//
	// pros::Motor armMotor(16);
	//
	// pros::c::ext_adi_ultrasonic_t ultrasonic = pros::c::ext_adi_ultrasonic_init(10, 'G', 'H');
	// pros::c::ext_adi_ultrasonic_t ultrasonic2 = pros::c::ext_adi_ultrasonic_init(10, 'C', 'D');
	//
	// pros::Motor spinner(20);
	//
	//
	// int min = 115;
	// int max = 120;
	//
	// pros::ADIEncoder rightEncoder('E', 'F', true);
	// pros::ADIEncoder backEncoder('C', 'D');
	//
	//
	// pros::ADIDigitalOut piston('A');
	//
	// PIDController drivePID =  PIDController(0.15, 0, 0.1);
	// PIDController turnPID =  PIDController(0.5, 0, 0.1);
	//
	// const double TICKS_TO_INCHES = (2.75*M_PI)/360;
	//
	// int target = 21;
	//
	// rightEncoder.reset();
	// piston.set_value(true);
	//
	// armMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	//
	// while(true){
	// 	int distance = pros::c::ext_adi_ultrasonic_get(ultrasonic);
	// 	int distance2 = pros::c::ext_adi_ultrasonic_get(ultrasonic2);
	//
	// 	master.print(2,2, "%d %d ", (distance), distance2);
	// 	if(distance2 > min + 5 && distance2 < max + 5){
	// 		spinner.move(0);
	// 		break;
	// 	}
	// 	else{
	// 		spinner.move(50);
	// 	}
	// }
	//
	// pros::delay(500);
	//
	//
	// while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target){
	// 	// int power = drivePID.updatePID(rightEncoder.get_value() * TICKS_TO_INCHES, -target);
	// 	// if(power < -127)
	// 	// {
	// 	// 	power = -127;
	// 	// }
	// 	//master.print(2,2,"%d", power);
	// 	drive.runRightDrive(-50);
	// 	drive.runLeftDrive(-50);
	// }
	// drive.runRightDrive(0);
	// drive.runLeftDrive(0);
	// pros::delay(25);
	//
	// rightEncoder.reset();
	//
	// target = 6;
	//
	// while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target){
	// 	//int power = drivePID.updatePID(rightEncoder.get_value() * TICKS_TO_INCHES, target) * 100;
	//
	// 	drive.runRightDrive(50);
	// 	drive.runLeftDrive(50);
	// }
	// drive.runRightDrive(0);
	// drive.runLeftDrive(0);
	// pros::delay(100);
	//
	// rightEncoder.reset();
	//
	// target = 3;
	//
	// while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target){
	// 	// int power = turnPID.updatePID(rightEncoder.get_value(), -target) * 100;
	// 	// master.print(2,2,"%d", power);
	// 	// drive.runRightDrive(-power);
	// 	// drive.runLeftDrive(power);
	//
	// 	drive.runRightDrive(50);
	// 	drive.runLeftDrive(-50);
	// }
	// drive.runRightDrive(0);
	// drive.runLeftDrive(0);
	// pros::delay(50);
	//
	// rightEncoder.reset();
	//
	// target = 24.5;
	//
	// while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target - 0.5){
	// 	int power = drivePID.updatePID(rightEncoder.get_value() * TICKS_TO_INCHES, -target) * 70;
	// 	if(power < -127)
	// 	{
	// 		power = -127;
	// 	}
	// 	drive.runRightDrive(power);
	// 	drive.runLeftDrive(power);
	// }
	// drive.runRightDrive(0);
	// drive.runLeftDrive(0);
	// pros::delay(100);
	//
	// rightEncoder.reset();
	//
	// target = 3;
	//
	// while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target){
	// 	// int power = turnPID.updatePID(rightEncoder.get_value(), -target) * 100;
	// 	// master.print(2,2,"%d", power);
	// 	// drive.runRightDrive(-power);
	// 	// drive.runLeftDrive(power);
	//
	// 	drive.runRightDrive(-50);
	// 	drive.runLeftDrive(50);
	// }
	// drive.runRightDrive(0);
	// drive.runLeftDrive(0);
	// pros::delay(50);
	//
	// armMotor.tare_position();
	// while(armMotor.get_position() > -1500)
	// {
	// 	armMotor.move_velocity(-90);
	// 	pros::delay(25);
	// }
	// armMotor.move_velocity(0);
	//
	// target = 19.5;
	// piston.set_value(false);
	// while(abs(rightEncoder.get_value() * TICKS_TO_INCHES) <= target){
	// 	drive.runRightDrive(-127);
	// 	drive.runLeftDrive(-127);
	// }
	// drive.runRightDrive(0);
	// drive.runLeftDrive(0);
	// pros::delay(50);
	//
	// rightEncoder.reset();
	//
	// pros::delay(500);
	// //Piston In
	// piston.set_value(true);
	//
	// pros::delay(1500);
	//
	// armMotor.tare_position();
	// while(armMotor.get_position() < 1480)
	// {
	// 	armMotor.move_velocity(90);
	// 	pros::delay(25);
	// }
	// armMotor.move_velocity(0);
	//
	// armMotor.tare_position();
	// while(armMotor.get_position() < 1480)
	// {
	// 	armMotor.move_velocity(90);
	// 	pros::delay(25);
	// }
	// armMotor.move_velocity(0);
	//
	//
	// while(true){
	// 	int distance = pros::c::ext_adi_ultrasonic_get(ultrasonic);
	// 	int distance2 = pros::c::ext_adi_ultrasonic_get(ultrasonic2);
	//
	// 	master.print(2,2, "%d %d ", (distance), distance2);
	// 	if(distance2 > min + 5 && distance2 < max + 5){
	// 		spinner.move(0);
	// 		break;
	// 	}
	// 	else{
	// 		spinner.move(50);
	// 	}
	// }
	//
	// pros::delay(500);




	// pros::Controller master(pros::E_CONTROLLER_MASTER);
	//
	// pros::c::ext_adi_ultrasonic_t ultrasonic = pros::c::ext_adi_ultrasonic_init(10, 'G', 'H');
	// pros::c::ext_adi_ultrasonic_t ultrasonic2 = pros::c::ext_adi_ultrasonic_init(10, 'C', 'D');
	//
	// pros::Motor spinner(20);
	//
	//
	// int min = 115;
	// int max = 120;
	//
	// int spinState = 0;
	//
	// int pot_val = pros::c::ext_adi_analog_calibrate(10, 'A');
	//
	// while(true){
	// 	bool spinBtn = master.get_digital_new_press(DIGITAL_X);
	// 	int distance = pros::c::ext_adi_ultrasonic_get(ultrasonic);
	// 	int distance2 = pros::c::ext_adi_ultrasonic_get(ultrasonic2);
	//
	// 	int read_val = pros::c::ext_adi_analog_read_calibrated(10, 'A');
	//
	//
	// 	if((distance > min && distance < max) && (distance2 > min + 5 && distance2 < max + 5) ){
	// 		spinner.move(0);
	// 		master.print(2,2, "%d %d ", (distance), distance2);
	// 		/break;
	// 	}
	// 	else{
	// 		spinner.move(50);
	// 	}
	//
	//
	// 	std::cout << read_val;
	// 	master.print(2,2, "%d", read_val);
	// 	pros::delay(10);
	// }


	// pros::ADIUltrasonic ultrasonic ('A', 'B');
	//
	// pros::Controller master(pros::E_CONTROLLER_MASTER);
	// pros::Motor left_mtr(1);
	// pros::Motor right_mtr(2);
	//
	//
	// while (true) {
	// 	pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
	// 	                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
	// 	                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
	// 	int left = master.get_analog(ANALOG_LEFT_Y);
	// 	int right = master.get_analog(ANALOG_RIGHT_Y);
	//
	// 	left_mtr = left;
	// 	right_mtr = right;
	//
	// 	pros::lcd::print(7, "%d", (ultrasonic.get_value()));
	//
	// 	pros::delay(20);
	// }
}
