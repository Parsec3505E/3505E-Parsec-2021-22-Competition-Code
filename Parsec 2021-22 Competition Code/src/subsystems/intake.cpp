#include "main.h"

Intake::Intake(){

  //Motor Objects
  intakeMotor = new pros::Motor(5);

}

//Drive Methods
void Intake::updatePower(int output){
  intakeMotor->move(output);
}

void Intake::moveVelocity(int velocity){
  intakeMotor->move_velocity(velocity);
}

void Intake::setBrake(){
  intakeMotor->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void Intake::setCoast(){
  intakeMotor->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

//Ring Detector Mehtods

int Intake::calibrateRingDetector(){
  return pros::c::ext_adi_analog_calibrate(10, 'C');
}

int Intake::ringDetectorGetVal(){
  return pros::c::ext_adi_analog_read(10, 'C');
}
