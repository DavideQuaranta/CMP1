//Conic.cc
#include "Conic.h"

//ConicSection Implementation


ConicSection::ConicSection(){
  type_ = findType();
}
ConicSection::ConicSection(float *params){
  for(int i = 0; i < 6; i++){
    coeff_[i] = params[i];
  }
  type_ = findType();
}
ConicSection::ConicSection(const ConicSection& conic){
  for(int i = 0; i < 6; i++){
    coeff_[i] = conic.coeff_[i];
  }
  type_ = findType();
}
ConicSection::~ConicSection(){
  cout << "~ConicSection() called" << endl;
}

float ConicSection::getCoeff(int i) const {
  return coeff_[i-1];
}
void ConicSection::setCoeff(int i, float newcoeff) {
  coeff_[i-1] = newcoeff;
  type_ = findType();
}
float ConicSection::discriminant() const {
  return coeff_[1]*coeff_[1] - 4*(coeff_[0]*coeff_[2]);
}
ostream& operator<<(ostream& os, const ConicSection& conic){

 std::map<int, std::string> types =
 {
    {0,std::string("Ellipse")},
    {1,std::string("Parabola")},
    {2,std::string("Hyperbola")}
 };

 os << "a = " << conic.coeff_[0]
 << " b = " << conic.coeff_[1]
 << " c = " << conic.coeff_[2]
 << " d = " << conic.coeff_[3]
 << " e = " << conic.coeff_[4]
 << " f = " << conic.coeff_[5] << "\n";
 os << "Discriminant = " << conic.discriminant() << " ("
 << types[conic.type_] << ")";
 os << "\n";
 return os;
}
