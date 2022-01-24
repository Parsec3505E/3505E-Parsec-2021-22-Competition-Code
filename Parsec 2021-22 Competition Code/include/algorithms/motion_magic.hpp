#ifndef _MOTION_HPP_INCLUDED
#define _MOTION_HPP_INCLUDED

#include "main.h"

class MotionMagic
{
  private:

    //Member Variables
    Odometry odometry;

    //Turn PID Loop
    double deltaX;
    double deltaY;
    double turnimgDistance;

    double radius;
    double alpha;
    double arcLength;
    double length;
    double speed;
    double k;

    double targetHeading;


  public:

    //Constructor
    MotionMagic();

    //Methods
    double turnToPoint(double targetX, double targetY);
    double driveToPoint(double targetX, double targetY);

};

#endif
