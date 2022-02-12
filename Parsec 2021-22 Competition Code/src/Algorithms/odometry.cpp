#include "main.h"

Odometry::Odometry(Drivetrain drivetrain){
      odom_drivetrain = drivetrain;
}


void Odometry::setStartLocation(Vector startPos, double startHeading){
  position = new Vector(startPos);
  startHeading =startHeading * (M_PI / 180);
  heading = normalizeRadians(heading + startHeading);

}

void Odometry::updatePos(){

  right_encoder_val = odom_drivetrain.getRightEncoderVal();
  left_encoder_val = odom_drivetrain.getLeftEncoderVal();
  back_encoder_val = odom_drivetrain.getBackEncoderVal();

  delta_right_val = right_encoder_val - prev_right_val;
  delta_left_val = left_encoder_val - prev_left_val;
  delta_back_val = back_encoder_val - prev_back_val;

  deltaHeading = (delta_left_val - delta_right_val) / (LEFT_ENCODER_OFFSET + RIGHT_ENCODER_OFFSET);
  heading += deltaHeading;

  if(deltaHeading == 0){
    deltax = delta_back_val;
    deltay = (delta_left_val + delta_right_val)/2;
  }else{
    localRadiusY = (delta_left_val / deltaHeading) - RIGHT_ENCODER_OFFSET;
    localRadiusX = (delta_back_val / deltaHeading) + BACK_ENCODER_OFFSET;

    localDisY = 2*sin(deltaHeading/2)*localRadiusY;
    localDisX = 2*sin(deltaHeading/2)*localRadiusX;

    deltax = sin(deltaHeading/2)*localDisX + cos(deltaHeading/2)*localDisY;
    deltay = cos(deltaHeading/2)*localDisX - sin(deltaHeading/2)*localDisY;
  }

  globalCentricDelta = new Vector(deltax, deltay);
  globalCentricDelta->rotate(heading);
  position->add(*globalCentricDelta);

  prev_left_val = left_encoder_val;
  prev_right_val = right_encoder_val;
  prev_back_val = back_encoder_val;

}

Vector* Odometry::getPos(){
  return position;
}

double Odometry::getHeading(){
  return heading;
}


double Odometry::normalizeRadians(double angle){
  while(angle >= 2*M_PI) {
      angle -= 2*M_PI;
  }
  while(angle < 0.0) {
      angle += 2*M_PI;
  }
  return angle;
}

// double Odometry::encoderToInch(double val) {
//   return (double)(val/NumberConstants::TICKS_TO_INCHES);
// }
