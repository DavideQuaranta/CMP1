// BH.cc
#include "BH.h"

BH BH::MassKai(double mass, double kai){
  return BH(mass,kai);
}
BH BH::Kai(double kai){
  return BH(1, kai);
}
BH BH::MassMirr(double mass, double mirr){
  double kai2 = 1 - ((2*mirr*mirr)/(mass*mass) - 1)*((2*mirr*mirr)/(mass*mass) - 1);
  return BH(mass, sqrt(kai2));
}
BH BH::MirrKai(double mirr, double kai){
  double m2 = 2*mirr*mirr/(1+sqrt(1-kai*kai));
  return BH(sqrt(m2), kai);
}
BH::BH(const BH& OldHole){
  mass_ = OldHole.mass_;
  kai_ = OldHole.kai_;
}
BH::~BH(){
  cout << "~BH() called." << endl;
}

double BH::getMass(){
  return mass_;
}
double BH::getKai(){
  return kai_;
}
double BH::getMirr(){
  return sqrt((mass_*mass_*0.5)*(1+sqrt(1-kai_*kai_)));
}
double BH::getE(){
  return mass_ - this->getMirr();
}

void BH::setMass(double newmass){
  mass_ = newmass;
}
void BH::setKai(double newkai){
  kai_ = newkai;
}
void BH::print(){
  cout << "\nYour Black Hole's Data:\n" << endl;
  cout << "Mass = " << mass_ << " solar masses " << endl;
  cout << "Kai = " << kai_ << endl;
  cout << "Irred. Mass = " << this->getMirr() << " solar masses " << endl;
  cout << "Penrose Energy = " << this->getE() << " solar masses " << endl;
  cout << "\n" << endl;
}


BBH::BBH(double mass1, double kai1, double theta1, double mass2, double kai2, double theta2){
  theta1_ = theta1;
  theta2_ = theta2;
  Hole1.setMass(mass1);
  Hole1.setKai(kai1);
  Hole2.setMass(mass2);
  Hole2.setKai(kai2);
  kai_eff = (kai1*mass1*cos(theta1) + kai2*mass2*cos(theta2))/(mass1+mass2);
}
BBH::BBH(const BBH& OldBBH){
  Hole1 = OldBBH.Hole1;
  Hole2 = OldBBH.Hole2;
  theta1_ = OldBBH.theta1_;
  theta2_ = OldBBH.theta2_;
  kai_eff = OldBBH.kai_eff;
}
BBH::~BBH(){
  cout << "~BBH() called." << endl;
}
void BBH::print(){
  Hole1.print();
  Hole2.print();
  cout << "Theta1 = " << theta1_ <<endl;
  cout << "Theta2 = " << theta2_ << endl;
  cout << "kai_eff = " << kai_eff <<endl;
  cout << "\n" << endl;
}
