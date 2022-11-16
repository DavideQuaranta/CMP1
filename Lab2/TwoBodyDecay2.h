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
// Double_t TwoBodyMomentum(float M, float m1, float m2){};
// TLorentzVector NewMomentum(TLorentzVector Old, double new_norm, float mass){};

class Particle{
public:

    Particle(float mass, string name){};

    void setMomentum(const double& px, const double& py, const double& pz){};

    TLorentzVector getMomentum(){};

    void Boost(TVector3 beta){};

    TVector3 getBeta(){};
    double getGamma(){};
    float getMass(){};

    void print(){};

private:
    float mass_;
    TVector3 beta_;
    double gamma_;
    string name_;
    TLorentzVector p_;
};

class TwoBodyDecay{
public:
  TwoBodyDecay(Particle& father, Particle& Daughter1, Particle& Daughter2){};
private:
  float p_cms_;
  Double_t x, y, z;
  TRandom Polar, seed;
};

class Detector {
public:
    Detector(const double& s){};
    void setSigma(const double& s){};

    double measure(TVector3 momentum){};
private:
    double sigma_,mod_mom;
    TRandom Response;
};
