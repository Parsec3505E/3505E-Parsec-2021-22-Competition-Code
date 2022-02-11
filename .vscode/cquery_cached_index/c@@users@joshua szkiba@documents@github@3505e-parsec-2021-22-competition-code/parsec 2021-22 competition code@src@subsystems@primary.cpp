#include "main.h"

Primary::Primary(){

  //Motor Objects
  spinnerMotor = new pros::Motor(7);
  clamp = new pros::ADIDigitalOut('G');
  ultrasonic = pros::c::ext_adi_ultrasonic_init(10, 'A', 'B');
}

//Drive Methods
void Primary::updatePower(int output){
  spinnerMotor->move(output);
}


void Primary::setBrake(){
  spinnerMotor->set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void Primary::setCoast(){
  spinnerMotor->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

//Piston Methods
void Primary::extend(){
  clamp->set_value(true);
}

void Primary::retract(){
  clamp->set_value(false);
}

//Ring Detector Mehtods

void Primary::ultrasonicGetVal(){
  pros::c::ext_adi_ultrasonic_get(ultrasonic);
}

void Primary::ultrasonicShutDown(){
  pros::c::ext_adi_ultrasonic_shutdown(ultrasonic);
}
