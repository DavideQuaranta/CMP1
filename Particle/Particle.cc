//Particle.cc
#include "Particle.h"

//Constructors
Particle::Particle() {}
Particle::Particle(const float& mass, const float *x, const float *v){
  mass_ = mass;
  for(int i=0; i<3; i++){
    x_[i] = x[i];
    v_[i] = v[i];
  }
}
Particle::Particle(const Particle& oldParticle){
  mass_ = oldParticle.mass_;
  for(int i=0; i<3; i++){
    x_[i] = oldParticle.x_[i];
    v_[i] = oldParticle.v_[i];
  }}
Particle::~Particle(){
    //clcout << "\n~Particle() called. \n" << endl;
  }
//getters
float Particle::getMass() const {
  return mass_;
}
float Particle::getx(int i) const {
  return x_[i];
}
float Particle::getv(int i) const {
  return v_[i];
}
//setters
void Particle::setMass(const float& newMass){
  mass_ = newMass;
}
void Particle::setx(int i, const float& newx){
  x_[i] = newx;
}
void Particle::setv(int i, const float& newv){
  v_[i] = newv;
}
//print
void Particle::print(){
  cout << "\nYour Particle's data: \n" << endl;
  cout << "mass = " << mass_ << "" << endl;
  cout << "x = (" << x_[0] << " , " << x_[1] << " , "
  << x_[2] << ") " << endl;
  cout << "v = (" << v_[0] << " , " << v_[1] << " , "
  << v_[2] << ") \n" << endl;
}


Ensemble::Ensemble(int N, const string& dist, const float& param1, const float& param2,
  const float& param3, const float& param4, const float& param5, const float& param6){

  float randMass, randX[3], randV[3];

  if(dist == "uniform"){
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis1(param1, param2);
    std::uniform_real_distribution<> dis2(param3, param4);
    std::uniform_real_distribution<> dis3(param5, param6);
    for (int i = 0; i < N; i++){
      randMass = dis1(gen);
      total_mass += randMass;
      for(int j = 0; j < 3; j++){
        randX[j] = dis2(gen);
        randV[j] = dis3(gen);
        CoM[j] += randMass*randX[j];
        T += 0.5*randMass*randV[j]*randV[j];
      }

      Particles_.push_back(Particle(randMass, randX, randV));

    }

    T = (2.0/3.0*kb)*(T/N);
    CoM[0] = CoM[0]/total_mass;
    CoM[1] = CoM[1]/total_mass;
    CoM[2] = CoM[2]/total_mass;

  }


  else if(dist == "normal"){
    std::default_random_engine generator;
    std::normal_distribution<double> dis1(param1,param2);
    std::normal_distribution<double> dis2(param3,param4);
    std::normal_distribution<double> dis3(param5,param6);

    for(int i = 0; i < N; i++){
      randMass = dis1(generator);
      total_mass += randMass;
      for(int j = 0; j < 3; j++){
        randX[j] = dis2(generator);
        randV[j] = dis3(generator);
        CoM[j] += randMass*randX[j];
        T += 0.5*randMass*randV[j]*randV[j];
      }
      Particles_.push_back(Particle(randMass, randX, randV));
    }

    T = (2.0/3.0*kb)*(T/N);
    CoM[0] = CoM[0]/total_mass;
    CoM[1] = CoM[1]/total_mass;
    CoM[2] = CoM[2]/total_mass;
  }
}
Particle Ensemble::getParticle(int i){
  return Particles_[i];
}
Ensemble::~Ensemble(){
  cout << "~Ensemble called().\n" << endl;
}
void Ensemble::print(){
  cout << "\nYour Ensemble's data:\n" << endl;
  cout << "Total mass = " << total_mass << endl;
  cout << "CoM = (" << CoM[0] << " , " << CoM[1] << " , "
  << CoM[2] << ") " << endl;
  cout << "T = " << T << endl;
}
