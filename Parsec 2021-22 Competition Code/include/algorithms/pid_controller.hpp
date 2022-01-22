#ifndef _PID_HPP_INCLUDED
#define _PID_HPP_INCLUDED

#include "main.h"

class PIDController
{
  private:

    //Member Variables
    double target;
    double error;
    double prev_error;
    double integral;
    double integral_wind_up;
    double derivative;

    double kP;
    double kI;
    double kD;


  public:

    //Constructor
    PIDController(double kP, double kI, double kD);

    //Methods
    double updatePID(double input, double target);

};

#endif
