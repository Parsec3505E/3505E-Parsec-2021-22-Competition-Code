#ifndef _DRIVE_HPP_INCLUDED
#define _DRIVE_HPP_INCLUDED

#include "main.h"

class Drivetrain
{
  private:

    //Motors
    pros::Motor* rightFront;
    pros::Motor* rightBack;
    pros::Motor* leftFront;
    pros::Motor* leftBack;

    //Encoders
    pros::ADIEncoder* rightEncoder;
    pros::ADIEncoder* leftEncoder;
    pros::ADIEncoder* backEncoder;

  public:

    //Constructor
    Drivetrain();

    //Drive Methods
    void runRightDrive(int output);
    void runLeftDrive(int output);
    void setRightVelocity(int velocity);
    void setLeftVelocity(int velocity);

    //Motor Methods
    void setBrake();
    void setCoast();

    //Encoder Methods

    //Get Encoder Values
    int getRightEncoderVal();
    int getLeftEncoderVal();
    int getBackEncoderVal();

    //Reset Encoders
    void resetRightEncoder();
    void resetLeftEncoder();
    void resetBackEncoder();


};

#endif
