#include "main.h"

Drivetrain::Drivetrain(){
  //Motor Objects
  rightFront = new pros::Motor(11, true);
  rightBack = new pros::Motor(6, true);
	leftFront = new pros::Motor(4);
	leftBack = new pros::Motor(17);



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

void Drivetrain::setHold(){
  rightFront->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  rightBack->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  leftFront->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  leftBack->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
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

int Drivetrain::getRightIntegrated(){
  return rightFront->get_position();
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


//Auton Methods
void Drivetrain::move_forward(int distance, int vel){

  resetIntegrated();
  while(abs(getRightIntegrated()) <= distance){
  	setRightVelocity(vel);
  	setLeftVelocity(vel);
  }
  setRightVelocity(0);
  setLeftVelocity(0);


}

void Drivetrain::move_backward(int distance, int vel){
  resetIntegrated();
  while(abs(getRightIntegrated()) <= distance){
  	setRightVelocity(-vel);
  	setLeftVelocity(-vel);
  }
  setRightVelocity(0);
  setLeftVelocity(0);
}

void Drivetrain::turn_right(int distance, int vel){
  resetIntegrated();
  while(abs(getRightIntegrated()) <= distance){
  	setRightVelocity(-vel);
  	setLeftVelocity(vel);
  }
  setRightVelocity(0);
  setLeftVelocity(0);
}

void Drivetrain::turn_left(int distance, int vel){
  resetIntegrated();
  while(abs(getRightIntegrated()) <= distance){
  	setRightVelocity(vel);
  	setLeftVelocity(-vel);
  }
  setRightVelocity(0);
  setLeftVelocity(0);
}

// Reseting integrated encoders
void Drivetrain::resetIntegrated(){
  rightFront->tare_position();
  rightBack->tare_position();
  leftFront->tare_position();
  leftBack->tare_position();
}
