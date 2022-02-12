#include "main.h"

Vector::Vector(double component1, double component2){

  std::array<double,2> components =  {component1, component2};
  this->R = R;
  this->theta = theta;
  genAngles();

}

//Drive Methods

void Vector::genMag() {

  R = sqrt(pow(components[0], 2) + pow(components[1], 2));
}

void Vector::genAngles() {
  genMag();

  if (components[0] == 0 && components[1] == 0) {
      theta = 0;
  } else {

      if (components[0] == 0) {

          theta = M_PI / 2;

          if (components[1] < 0) {
              theta *= -1;
          }
      } else {

          theta = atan(components[1] / components[0]);

          if (components[0] < 0) {

              if (components[1] >= 0) {

                  theta += M_PI;
              } else if (components[1] < 0) {
                  theta -= M_PI;
              } else {
                  theta = M_PI;
              }
          }
      }
  }
}

void Vector::generate_component(){
  double components[2];

  components[0] = R * cos(theta);
  components[1] = R * sin(theta);

}

double Vector::getMag(){
  return R;
}

void Vector::rotate(double radians) {
  genMag();
  this->theta = (int)(theta + radians) % (int)(2 * M_PI);
  generate_component();
}

std::array<double,2> Vector::getComponents(){
  std::array<double,2> new_comp;
  for(int i = 0; i < 2; i++){
    components[i] = new_comp[i];
  }
  return new_comp;

}

double Vector::getComponent(int component){
  if(component >= 0 && component < 2){
    return components[component];
  }
  else{
    return 0;
  }
}


void Vector::add(Vector vector) {

  std::array<double,2> two_comp;
  two_comp = vector.getComponents();

  components[0] += two_comp[0];
  components[1] += two_comp[1];

  genAngles();
}
