#ifndef _INTAKE_HPP_INCLUDED
#define _INTAKE_HPP_INCLUDED

#include "main.h"

class Intake
{
  private:

    //Motors
    pros::Motor* intakeMotor;


  public:

    //Constructor
    Intake();

    //Drive Methods
    void updatePower(int output);
    void moveVelocity(int velocity);

    //Motor Methods
    void setBrake();
    void setCoast();

    //Ring Detector Methods
    int calibrateRingDetector();
    int ringDetectorGetVal();

};

#endif
