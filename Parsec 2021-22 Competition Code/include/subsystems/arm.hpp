#ifndef _ARM_HPP_INCLUDED
#define _ARM_HPP_INCLUDED

#include "main.h"

class Arm
{
  private:

    //Motors
    pros::Motor* armMotor;

    const int HIGH_BRANCH = -1000;
    const int MEDIUM_BRANCH = -2000;
    const int LOW_BRANCH = -333;
    const int RESET = 0;


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

    //Move to specific heights to score on the different branches
    int getError(); //Get the error of how far off the arm is from it's target/setpoint

    void moveToHigh();
    void moveToMedium();
    void moveToLow();
    void moveToReset();

};

#endif
