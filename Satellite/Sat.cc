// Sat.cc
#include <math.h>
#include "Sat.h"
#include <fstream>

Planet::Planet(){
  R_ = 0;
  mass_ = 0;
}
Planet::Planet(double R, double mass, double G){
  mass_ = mass;
  R_ = R;
  G_ = G;
}
double Planet::Mass(){return mass_;}
double Planet::G(){return G_;}

Atmosphere::Atmosphere(double h, double F10, double Ap){
  h_ = h;
  F10_ = F10;
  Ap_ = Ap;
  double mu = 27 - 0.012*(h-200);
  double T = 900 + 2.5*(F10 - 70) + 1.5*Ap;
  rho_ = 6e-10 * exp(-((h_ - 175)*mu)/T);
}
void Atmosphere::seth(double h){
  h_ = h;
  double mu = 27 - 0.012*(h-200);
  double T = 900 + 2.5*(F10_ - 70) + 1.5*Ap_;
  rho_ = 6e-10 * exp(-((h_ - 175)*mu)/T);
}

Satellite::Satellite(double *x, double *v, double A, double Cd, double mass){
  for(int i=0; i<3; i++){
    x_[i] = x[i];
    v_[i] = v[i];
  }
  A_ = A;
  Cd_ = Cd;
  mass_ = mass;
}

double Satellite::mass(){return mass_;}
double Satellite::A(){return A_;}
double Satellite::Cd(){return Cd_;}
double Satellite::x(int i){return x_[i];}
double Satellite::v(int i){return v_[i];}

FlySatellite::FlySatellite(Planet planet, Atmosphere atmo, Satellite sat){
  planet_ = planet;
  atmo_ = atmo;
  sat_ = sat;
}

void Euler::simulation(double T, double dt){
  double t = 0;
  double M = planet_.Mass(), m = sat_.mass();
  double G = planet_.G();
  double h, A = sat_.A(), Cd = sat_.Cd();
  double x = sat_.x(0), vx = sat_.v(0);
  double y = sat_.x(1), vy = sat_.v(1);
  double z = sat_.x(2), vz = sat_.v(2);

  ofstream outfile;
  outfile.open ("sim.dat");

  for(int i = 0; i < int(T/dt); i++){
    t += dt;
    double oldvx = vx, oldvy = vy, oldvz = vz;

    h = sqrt(x*x + y*y + z*z);
    atmo_.seth(sqrt(h);
    v2 = vx*vx + vy*vy + vz*vz;
    vx += (-G*(M*x)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd)*dt;
    vy += (-G*(M*y)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd)*dt;
    vz += (-G*(M*z)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd)*dt;

    x += oldvx*dt;
    y += oldvy*dt;
    z += oldvz*dt;

    outfile << x << "\t" << y << "\t" << z << "\t"
    << vx << "\t" << vy << "\t" << vz;



  }

  outfile.close();

}

void RungeKutta2::simulation(double T, double dt){
  double t = 0;
  double M = planet_.mass_, m = sat_.mass_;
  double G = planet_.G_;
  double h, A = sat_.A_, Cd = sat_.Cd;
  double x = sat_.x_[0], vx = sat_.v_[0];
  double y = sat_.x_[1], vy = sat_.v_[1];
  double z = sat_.x_[2], vz = sat_.v_[2];

  ofstream outfile;
  outfile.open ("sim.dat");

  double K1x, K1y, K1z, K2x, K2y, K2z;
  double K1vx, K1vy, K1vz, K2vx, K2vy, K2vz;

  for(int i = 0; i < int(T/dt); i++){

    t += dt;

    double oldvx = vx, oldvy = vy, oldvz = vz;
    double halfx, halfy, halfz, halfvx, halfvy, halfvz;

    h = sqrt(x*x + y*y + z*z);
    atmo_.seth(sqrt(h);
    v2 = vx*vx + vy*vy + vz*vz;
    K1vx = (-G*(M*x)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd);
    K1vy = (-G*(M*y)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd);
    K1vz = (-G*(M*z)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd);
    halfx = x + oldvx*dt*0.5;
    halfy = y + oldvy*dt*0.5;
    halfz = z + oldvz*dt*0.5;
    halfvx = oldvx + K1vx*dt*0.5;
    halfvy = oldvy + K1vy*dt*0.5;
    halfvz = oldvz + K1vz*dt*0.5;
    h = sqrt(halfx*halfx + halfy*halfy + halfz*halfz);
    atmo_.seth(sqrt(h);
    v2 = halfvx*halfvx + halfvy*halfvy + halfvz*halfvz;
    K2vx = (-G*(M*halfx)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd);
    K2vy = (-G*(M*halfy)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd);
    K2vz = (-G*(M*halfz)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd);
    vx += K2vx*dt;
    vy += K2vy*dt;
    vz += K2vz*dt;

    halfvx = oldvx + (-G*(M*x)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd)*dt*0.5;
    halfvy = oldvy + (-G*(M*y)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd)*dt*0.5;
    halfvz = oldvz + (-G*(M*z)/pow(h, 1.5) + (1/m)*(-0.5)*atmo_.rho_*v2*A*Cd)*dt*0.5;

    x += halfvx*dt;
    y += halfvy*dt;
    z += halfvz*dt;

    outfile << x << "\t" << y << "\t" << z << "\t"
    << vx << "\t" << vy << "\t" << vz;

  }
    outfile.close();

}
