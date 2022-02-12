#ifndef _ODOMETRY_HPP_INCLUDED
#define _ODOMETRY_HPP_INCLUDED

#include "main.h"

class Odometry {
  private:

    //Encoders
    Drivetrain odom_drivetrain;

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
    double RIGHT_ENCODER_OFFSET = 0;
    double LEFT_ENCODER_OFFSET= 0;
    double BACK_ENCODER_OFFSET = 0;


    Vector* position;
    Vector* localCentricDelata;
    Vector* globalCentricDelta;

  public:

    Odometry(Drivetrain drivetrain);


    void setStartLocation(Vector startPos, double startHeading);

    void updatePos();

    Vector* getPos();

    double getHeading();

    double normalizeRadians(double angle);

    // double encoderToInch(double val);





};

#endif
