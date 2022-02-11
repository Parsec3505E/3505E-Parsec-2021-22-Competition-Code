#include "main.h"
#include "time.h"

RateLimiter::RateLimiter(double cap){
  this->cap = cap;
}

//Drive Methods
double RateLimiter::update_delta_power(double req_power){

  time_t curr_time;

  double new_power;

  double delta_power = req_power - prev_power;
  double delta_time = curr_time - prev_time;

  double rate = delta_power / delta_time;

  if (rate > cap) {
    rate = cap;
  }
  else if(rate < -cap){
    rate = -cap;
  }
  else {
    rate = rate;
  }

  new_power = rate * delta_time;

  prev_time = curr_time;
  prev_power = req_power;

  return new_power;
}
