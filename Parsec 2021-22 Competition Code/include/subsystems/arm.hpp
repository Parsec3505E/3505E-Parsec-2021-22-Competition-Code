#ifndef _ARM_HPP_INCLUDED
#define _ARM_HPP_INCLUDED

#include "main.h"

class Arm
{
  private:

    //Motors
    pros::Motor* armMotor;


  public:

    //Constructor
    Arm();

    //Drive Methods
    void updatePower(int output);
    void moveVelocity(int velocity);

    //Motor Methods
    void setBrake();
    void setCoast();

    //Ring Detector Methods
    int calibratePot();
    int potGetVal();

};

#endif
