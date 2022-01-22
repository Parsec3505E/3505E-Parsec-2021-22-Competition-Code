#ifndef _PRIMARY_HPP_INCLUDED
#define _PRIMARY_HPP_INCLUDED

#include "main.h"

class Primary
{
  private:

    //Motors
    pros::Motor* spinnerMotor;
    pros::ADIDigitalOut* clamp;
    pros::c::ext_adi_ultrasonic_t ultrasonic;


  public:

    //Constructor
    Primary();

    //Motor Methods
    void updatePower(int output);
    void setBrake();
    void setCoast();

    //Piston Methods
    void extend();
    void retract();


    //Ultrasonic Methods
    void ultrasonicGetVal();
    void ultrasonicShutDown();


};

#endif
