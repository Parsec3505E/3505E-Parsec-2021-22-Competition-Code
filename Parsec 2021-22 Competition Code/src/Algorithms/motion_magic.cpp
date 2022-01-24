#include "main.h"

MotionMagic::MotionMagic(){
  odometry = Odometry(Drivetrain.rightEncoder, Drivetrain.leftEncoder, Drivetrain.backEncoder);

}

//Drive Methods
double MotionMagic::turnToPoint(double targetX, double targetY){
  current_pos = odometry.getPos();
  current_heading = odometry.getHeading();

  deltaX = targetX - currentX;
  deltaY = targetY - currentY;

  targetHeading = atan(-deltaX/deltaY);

  if(deltaY > 0){
    alpha = targetHeading - current_heading;
  }
  else{
    alpha = (targetHeading - current_heading) + M_PI;
  }

  if(alpha > M_PI){
    alpha = ((2*M_PI) - alpha)*-1;
  }
  else if(alpha < -M_PI){
    alpha = ((2*M_PI) + alpha);
  }

  return alpha;


}
