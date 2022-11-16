#include "TwoBodyDecay.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "TH1F.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TRandom.h"
#include "TLorentzVector.h"
#include <cstdlib>
#include "TFile.h"
#include "TTree.h"
#include "TLegend.h"
#include "TString.h"
#include <fstream>
#include <iomanip>
using namespace std;




// Classes and Functions
// Double_t TwoBodyMomentum(float M, float m1, float m2){
//     return sqrt(pow(M, 4) + pow(m1,4) + pow(m2,4) -2*pow(M*m1,2) -2*pow(M*m2,2) -2*pow(m2*m1,2))/(2*M);
// }
// TLorentzVector NewMomentum(TLorentzVector Old, double new_norm, float mass){
//
//     TLorentzVector New;
//     double px, py, pz, E;
//     double norm = Old.Vect().Mag();
//     px = new_norm*(Old.Px()/norm);
//     py = new_norm*(Old.Py()/norm);
//     pz = new_norm*(Old.Pz()/norm);
//     E = sqrt(px*px + py*py + pz*pz + mass*mass);
//     New.SetPxPyPzE(px,py,pz,E);
//     return New;
//
// }



Particle::Particle(float mass, string name){
    mass_ = mass;
    name_ = name;
}

void Particle::setMomentum(const double& px, const double& py, const double& pz){
    p_.SetPxPyPzE(px,py,pz, sqrt(px*px + py*py + pz*pz + mass_*mass_));
    beta_ = p_.BoostVector();
    gamma_ = p_.Gamma();
}

TLorentzVector Particle::getMomentum(){ return p_;}

void Particle::Boost(TVector3 beta){
    p_.Boost(beta);
}

TVector3 Particle::getBeta(){return beta_;}
double Particle::getGamma(){return gamma_;}
float Particle::getMass(){return mass_;}

void Particle::print(){
    cout << "\n" << endl;
    cout << name_ << " : " << endl;
    cout << "mass = " << mass_ << " MeV" << endl;
    p_.Print();
    cout << "\n" << endl;

}



TwoBodyDecay::TwoBodyDecay(Particle& father, Particle& Daughter1, Particle& Daughter2){
  p_cms_ = TwoBodyMomentum(father.getMass(), Daughter1.getMass(), Daughter2.getMass());
  Polar.SetSeed(rand());
  Polar.Sphere(x,y,z,p_cms_);
  Daughter1.setMomentum(x,y,z);
  Daughter2.setMomentum(-x,-y,-z);
  Daughter1.Boost(father.getBeta());
  Daughter2.Boost(father.getBeta());

}


Detector::(const double& s){
    sigma_=s;
}
void Detector::setSigma(const double& s){
    sigma_=s;
}

double Detector::measure(TVector3 momentum){
    mod_mom= momentum.Mag();
    return Response.Gaus(mod_mom,mod_mom*sigma_);
}
