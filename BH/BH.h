// BH.h
#include <cmath>
#include <iostream>
using namespace std;

class BH {
public:
  static BH MassKai(double mass, double kai = 0);
  static BH Kai(double kai);
  static BH MassMirr(double mass, double mirr);
  static BH MirrKai(double mirr, double kai);
  BH(const BH& OldHole);
  ~BH();

  double getMass();
  double getKai();
  double getMirr();
  double getE();

  void setMass(double newmass);
  void setKai(double newkai);

  void print();

private:
  double mass_, kai_;
  BH(double mass, double kai){
    mass_ = mass;
    kai_ = kai;
  };

};

class BBH {
public:

  BBH(double mass1, double kai1, double theta1, double mass2, double kai2, double theta2);
  BBH(const BBH& OldBBH);
  ~BBH();

  void print();
private:
  BH Hole1 = BH(BH::MassKai(1, 0));
  BH Hole2 = BH(BH::MassKai(1, 0));
  double kai_eff, theta1_, theta2_;
};
