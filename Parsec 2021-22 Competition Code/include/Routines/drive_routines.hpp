#ifndef _DRIVEROUTINES_HPP_INCLUDED
#define _DRIVEROUTINES_HPP_INCLUDED

#include "main.h"

const double TICKS_TO_INCHES = (2*M_PI*2)/360;

//Drive Methods
void driveToPoint(int target);
void turnToPoint(int target);


#endif
