//app.cpp
#include "Capacitors.h"
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main() {
  Capacitor myCap2 = Capacitor(10e-12);
  Capacitor myCap3 = Capacitor(5e-12);
  Capacitor myCap4 = Capacitor(15e-12);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(1e-12, 100e-12);

  int N = 1000;

  ofstream outfile;
  outfile.open ("true.dat");

  for(int i = 0; i < N; i++){
      double C1 = dis(gen);
      Capacitor myCap1 = Capacitor(C1);
      double CEq = ((myCap1 || myCap2) + (myCap3 || myCap4)).getCapacitance();

      outfile << C1 << "\t" << CEq <<endl;

  }

  outfile.close();

  return 0;
}
