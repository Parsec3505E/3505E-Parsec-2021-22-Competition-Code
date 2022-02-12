#include "main.h"

MotionMagic::MotionMagic(Drivetrain drivetrain){
  odometry = new Odometry(drivetrain);
}

//Drive Methods
double MotionMagic::turnToPoint(double targetX, double targetY){
  Vector* current_pos = odometry->getPos();
  double current_heading = odometry->getHeading();

  deltaX = targetX - current_pos->getComponent(0);
  deltaY = targetY - current_pos->getComponent(1);

  targetHeading = atan(-deltaX/deltaY);

  if(deltaY > 0){
    targetHeading += M_PI;
  }

  alpha = targetHeading - current_heading;

  if(alpha > M_PI){
    alpha = ((2*M_PI) - alpha)*-1;
  }
  else if(alpha < -M_PI){
    alpha = ((2*M_PI) + alpha);
  }

  return alpha;


}
