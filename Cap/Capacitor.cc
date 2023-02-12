//Capacitor.cc
#include <iostream>
#include <cmath>
#include "Capacitor.h"
using namespace std;

//implementation of constructors via named cosntructor idiom
Capacitor Capacitor::Q(double Q, double R1, double R2, double epsr){
  double Energy, Capacitance, Voltage;
  Capacitance = 4*pi*eps0*epsr*(R1*R2)/(R2-R1);
  Energy = 0.5*Q*Q/Capacitance;
  Voltage = 2*Energy/Q;
  return Capacitor(Q, Voltage, Energy, Capacitance);
}
Capacitor Capacitor::dV(double dV, double R1, double R2, double epsr){
  double Energy, Capacitance, Q;
  Capacitance = 4*pi*eps0*epsr*(R1*R2)/(R2-R1);
  Energy = 0.5*Capacitance*dV*dV;
  Q = 2*Energy/dV;
  return Capacitor(Q, dV, Energy, Capacitance);
}
Capacitor Capacitor::U(double U, double R1, double R2, double epsr){
  double Voltage, Capacitance, Q;
  Capacitance = 4*pi*eps0*epsr*(R1*R2)/(R2-R1);
  Q = sqrt(2*U*Capacitance);
  Voltage = 2*U/Q;
  return Capacitor(Q, Voltage, U, Capacitance);
}
// destructor
Capacitor::~Capacitor(){
  cout << "\n~Capacitor called.\n" << endl;
}

//getters
double Capacitor::getQ(){return Q_;}
double Capacitor::getC(){return C_;}
double Capacitor::getU(){return U_;}
double Capacitor::getdV(){return dV_;}

//print utility
void Capacitor::print(){
  cout << "\nYour Capacitor's Data: \n" << endl;
  cout << "Charge (Q) : " << Q_ << " Coulomb" << endl;
  cout << "Voltage (dV) : " << dV_ << " Volts" <<endl;
  cout << "Energy (U) : " << U_ << " Joule" << endl;
  cout << "Capacitance (C) : " << C_ << " Farad/meter\n" << endl;
}

CompositeCapacitor::CompositeCapacitor(double Q, double dV, double U, double C, std::vector<double> epsr) : Capacitor (Q,dV,U,C){
  epsr_ = epsr;
}
CompositeCapacitor CompositeCapacitor::Q(double Q, double R1, double R2, std::vector<double> epsr){
  double Energy, Voltage, r1, r2, Cinv = 0, Capacitance = 0;
  double d = (R2-R1)/epsr.size();
  std::vector<double> Cap;

  for(int i = 0; i < epsr.size(); i++){
    r1 = R1 + i*d;
    r2 = r1+d;
    Cap.push_back(4*pi*eps0*epsr[i]*(r1*r2)/(r2-r1));
    Cinv += 1/Cap[i];
  }

  Capacitance = 1/Cinv;
  Energy = 0.5*Q*Q/Capacitance;
  Voltage = 2*Energy/Q;
  return CompositeCapacitor(Q, Voltage, Energy, Capacitance, epsr);
}
CompositeCapacitor CompositeCapacitor::dV(double dV, double R1, double R2, std::vector<double> epsr){
  double Energy, Q, r1, r2, Cinv = 0, Capacitance = 0;
  double d = (R2-R1)/epsr.size();
  std::vector<double> Cap;

  for(int i = 0; i < epsr.size(); i++){
    r1 = R1+ i*d;
    r2 = r1+d;
    Cap.push_back(4*pi*eps0*epsr[i]*(r1*r2)/(r2-r1));
    Cinv += 1/Cap[i];
  }
  Capacitance = 1/Cinv;
  Energy = 0.5*Capacitance*dV*dV;
  Q = 2*Energy/dV;
  return CompositeCapacitor(Q, dV, Energy, Capacitance, epsr);
}
CompositeCapacitor CompositeCapacitor::U(double U, double R1, double R2, std::vector<double> epsr){
  double Voltage, Q, r1, r2, Cinv = 0, Capacitance = 0;
  double d = (R2-R1)/epsr.size();
  std::vector<double> Cap;

  for(int i = 0; i < epsr.size(); i++){
    r1 = R1+ i*d;
    r2 = r1+d;
    Cap.push_back(4*pi*eps0*epsr[i]*(r1*r2)/(r2+r1));
    Cinv += 1/Cap[i];
  }

  Q = sqrt(2*U*Capacitance);
  Voltage = 2*U/Q;
  return CompositeCapacitor(Q, Voltage, U, Capacitance, epsr);
}
// destructor
CompositeCapacitor::~CompositeCapacitor(){
  cout << "\n~CompositeCapacitor called.\n" << endl;
}
