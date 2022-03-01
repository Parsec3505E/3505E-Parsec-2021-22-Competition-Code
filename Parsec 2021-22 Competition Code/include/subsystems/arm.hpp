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
    void setHold();

    //Ring Detector Methods
    int calibratePot();
    int potGetVal();

    //Move to specific heights to score on the different branches
    int getError(int target);

    void moveToHigh(int vel);

    void moveToMedium(int vel);

    void moveToLow(int vel);

    void moveToReset(int vel);


    // Auton Methods
    void moveToSetpoint(int height, int vel);
    void preset(int setpoint, int vel);
    int getPose();
    void resetIntegrated();

};

#endif
