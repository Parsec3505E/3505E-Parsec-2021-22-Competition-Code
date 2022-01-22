#ifndef _RATE_LIMITER_HPP_INCLUDED
#define _RATE_LIMITER_HPP_INCLUDED

#include "main.h"

class RateLimiter
{
  private:

    double cap;
    double prev_power;
    time_t prev_time;

  public:

    //Constuctor
    RateLimiter(double cap);

    double update_delta_power(double req_power);

};

#endif
