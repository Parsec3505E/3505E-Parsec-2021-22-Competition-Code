#include "main.h"

Drivetrain::Drivetrain(){
  //Motor Objects
  rightFront = new pros::Motor(4, true);
  rightBack = new pros::Motor(11, true);
	leftFront = new pros::Motor(9);
	leftBack = new pros::Motor(6);

  setBrake();

  //Encoder Objects
  rightEncoder = new pros::ADIEncoder('A', 'B', true);
  leftEncoder = new pros::ADIEncoder('C', 'D');
  backEncoder = new pros::ADIEncoder('E', 'F');
}

//Drive Methods
void Drivetrain::runRightDrive(int output){
  rightFront->move(output);
  rightBack->move(output);
}

void Drivetrain::runLeftDrive(int output){
  leftFront->move(output);
  leftBack->move(output);
}

void Drivetrain::setRightVelocity(int velocity){
  rightFront->move_velocity(velocity);
  rightBack->move_velocity(velocity);
}

void Drivetrain::setLeftVelocity(int velocity){
  leftFront->move_velocity(velocity);
  leftBack->move_velocity(velocity);
}

void Drivetrain::setBrake(){
  rightFront->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  rightBack->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  leftFront->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  leftBack->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void Drivetrain::setCoast(){
  rightFront->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  rightBack->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  leftFront->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  leftBack->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

//Encoder Methods

int Drivetrain::getRightEncoderVal(){
  return rightEncoder->get_value();
}

int Drivetrain::getLeftEncoderVal(){
  return leftEncoder->get_value();
}

int Drivetrain::getBackEncoderVal(){
  return backEncoder->get_value();
}

void Drivetrain::resetRightEncoder(){
  rightEncoder->reset();
}

void Drivetrain::resetLeftEncoder(){
  leftEncoder->reset();
}

void Drivetrain::resetBackEncoder(){
  backEncoder->reset();
}
