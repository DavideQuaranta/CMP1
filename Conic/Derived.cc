#include "Conic.h"


CanonicalEllipse::CanonicalEllipse(float *params) : ConicSection(params){
  coeff_[0] = 1/(params[0]*params[0]);
  coeff_[1] = 0;
  coeff_[2] = 1/(params[1]*params[1]);
  coeff_[3] = 0;
  coeff_[4] = 0;
  coeff_[5] = -1;
  type_ = findType();
}
CanonicalEllipse::~CanonicalEllipse(){
  cout << "~CanonicalEllipse() called" << endl;
}

CanonicalParabola::CanonicalParabola(float *params) : ConicSection(params){
  coeff_[0] = params[0];
  coeff_[1] = 0;
  coeff_[2] = 0;
  coeff_[3] = params[1];
  coeff_[4] = -1;
  coeff_[5] = params[2];
  type_ = findType();
}
CanonicalParabola::~CanonicalParabola(){
  cout << "~CanonicalParabola() called" << endl;
}
float CanonicalParabola::FirstDerivative(const float& x){
  return 2*coeff_[0]*x + coeff_[3];
}
float CanonicalParabola::SecondDerivative(const float& x){
  return 2*coeff_[0];
}

CanonicalHyperbola::CanonicalHyperbola(float *params) : ConicSection(params){
  coeff_[0] = 1/(params[0]*params[0]);
  coeff_[1] = 0;
  coeff_[2] = -1/(params[1]*params[1]);
  coeff_[3] = 0;
  coeff_[4] = 0;
  coeff_[5] = -1;
  type_ = findType();
}
CanonicalHyperbola::~CanonicalHyperbola(){
  cout << "~CanonicalHyperbola() called" << endl;
}
