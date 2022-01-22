#ifndef _VECTOR_HPP_INCLUDED
#define _VECTOR_HPP_INCLUDED

#include "main.h"
#include <cmath>
#include <iostream>
#include <array>

class Vector
{
  private:

    double R;
    double theta;
    std::array<double,2> components;

  public:

    //Constuctor
    Vector(double component1, double component2);

    void genMag();
    void genAngles();
    void generate_component();
    double getMag();
    void rotate(double radians);
    std::array<double, 2> getComponents();
    double getComponent(int component);
    void add(Vector vector);

};

#endif
