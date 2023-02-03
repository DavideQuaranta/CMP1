//Particle.h
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
using namespace std;

class Particle {
public:
  //Constructors
  Particle();
  Particle(const float& mass, const float *x, const float *v);
  Particle(const Particle& oldParticle);
  ~Particle();
  //getters
  float getMass() const;
  float getx(int i) const;
  float getv(int i) const;
  //setters
  void setMass(const float& newMass);
  void setx(int i, const float& newx);
  void setv(int i, const float& newv);
  //print utility
  void print();
private:
  float mass_;
  float x_[3], v_[3];
};

class Ensemble {
public:
  Ensemble(int N, const string& dist, const float& param1, const float& param2,
  const float& param3, const float& param4, const float& param5, const float& param6);
  ~Ensemble();
  Particle getParticle(int i);
  void print();
private:
  std::vector<Particle> Particles_;
  float total_mass = 0;
  float CoM[3];
  float T=0;
  float kb = 1.3806e-23;
};
