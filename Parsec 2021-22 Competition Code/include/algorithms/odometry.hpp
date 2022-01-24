#ifndef _ODOMETRY_HPP_INCLUDED
#define _ODOMETRY_HPP_INCLUDED

#include "main.h"

class Odometry {
  private:

    //Encoders
    pros::ADIEncoder* rightEncoder;
    pros::ADIEncoder* leftEncoder;
    pros::ADIEncoder* backEncoder;

    //Member Variables
    double right_encoder_val;
    double prev_right_val;
    double delta_right_val;

    double left_encoder_val;
    double prev_left_val;
    double delta_left_val;

    double back_encoder_val;
    double prev_back_val;
    double delta_back_val;

    //Heading and Angle
    double heading;
    double deltaHeading;

    double average_orientation;

    double localRadiusX;
    double localRadiusY;

    double localDisX;
    double localDisY;

    //Encoder Directions
    int lEncoderDirection;
    int rEncoderDirection;
    int bEncoderDirection;

    // Final Differential Coordinate Values
    double deltax;
    double deltay;

    //Constants
    const double RIGHT_ENCODER_OFFSET;
    const double LEFT_ENCODER_OFFSET;
    const double BACK_ENCODER_OFFSET;


    Vector* position;
    Vector* localCentricDelata;
    Vector* globalCentricDelta;

  public:

    Odometry(pros::ADIEncoder *rightEncoder, pros::ADIEncoder *leftEncoder, pros::ADIEncoder *backEncoder);


    void setStartLocation(Vector startPos, double startHeading);

    void updatePos();

    Vector* getPos();

    double getHeading();

    double normalizeRadians(double angle);

    // double encoderToInch(double val);





};

#endif
