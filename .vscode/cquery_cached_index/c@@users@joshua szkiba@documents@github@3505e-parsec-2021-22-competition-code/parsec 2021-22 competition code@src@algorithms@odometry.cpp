#include "main.h"

Odometry::Odometry(pros::ADIEncoder *rightEncoder, pros::ADIEncoder *leftEncoder, pros::ADIEncoder *backEncoder){
      this->rightEncoder = rightEncoder;
      this->leftEncoder = leftEncoder;
      this->backEncoder = backEncoder;

}


void Odometry::setStartLocation(Vector startPos, double startHeading){
  position = new Vector(startPos);
  startHeading =startHeading * (M_PI / 180);
  heading = normalizeRadians(heading + startHeading);

}

void Odometry::updatePos(){

  right_encoder_val = rightEncoder->get_value();
  left_encoder_val = leftEncoder->get_value();
  back_encoder_val = backEncoder->get_value();

  delta_right_val = right_encoder_val - prev_right_val;
  delta_left_val = left_encoder_val - prev_left_val;
  delta_back_val = back_encoder_val - prev_back_val;

  deltaHeading = (delta_left_val - delta_right_val) / (LEFT_ENCODER_OFFSET + RIGHT_ENCODER_OFFSET);
  heading += deltaHeading;

  if(deltaHeading == 0){
    deltaX = delta_back_val;
    deltaY = (delta_left_val + delta_right_val)/2;
  }else{
    localRadiusY = (delta_left_val / deltaHeading) - RIGHT_ENCODER_OFFSET;
    localRadiusX = (delta_back_val / deltaHeading) + BACK_ENCODER_OFFSET;

    localDisY = 2*sin(deltaHeading/2)*localRadiusY;
    localDisX = 2*sin(deltaHeading/2)*localRadiusX;

    deltaY = sin(deltaHeading/2)*localDisX + cos(deltaHeading/2)*localDisY;
    deltaX = cos(deltaHeading/2)*localDisX - sin(deltaHeading/2)*localDisY;
  }

  globalCentricDelta = new Vector(deltaX, deltaY);
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
