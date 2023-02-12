// Capacitors.cc
#include <iostream>
#include "Capacitors.h"
using namespace std;

Capacitor::Capacitor(double Capacitance){
  C_ = Capacitance;
}
Capacitor::Capacitor(double Area, double d, double eps){
  C_ = (eps0*eps*Area)/d;
}
Capacitor::Capacitor(const Capacitor& OldCapacitor){
  C_ = OldCapacitor.C_;
}

void Capacitor::setCapacitance(double newcap){C_ = newcap;}
double Capacitor::getCapacitance(){return C_;}

void Capacitor::print(){
  cout << "\nYour Capacitor's Data : \n" << endl;
  cout << "Capacitance : " << this->getCapacitance() << " F \n"<< endl;
}

Capacitor Capacitor::operator+(const Capacitor& SecondCapacitor){
  double cap = (1/C_) + (1/SecondCapacitor.C_);
  return Capacitor(1/cap);
}

Capacitor Capacitor::operator||(const Capacitor& SecondCapacitor){
  return Capacitor(C_ + SecondCapacitor.C_);
}
