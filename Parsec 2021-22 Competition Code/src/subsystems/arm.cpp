#include "main.h"

Arm::Arm(){

  //Motor Objects
  armMotor = new pros::Motor(6);

}

//Drive Methods
void Arm::updatePower(int output){
  armMotor->move(output);
}

void Arm::moveVelocity(int velocity){
  armMotor->move_velocity(velocity);
}

void Arm::setBrake(){
  armMotor->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void Arm::setCoast(){
  armMotor->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

//Ring Detector Mehtods

int Arm::calibratePot(){
  return pros::c::ext_adi_analog_calibrate(10, 'C');
}

int Arm::potGetVal(){
  return pros::c::ext_adi_analog_read(10, 'C');
}
