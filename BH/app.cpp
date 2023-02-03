// app.cpp
#include <iostream>
#include <string>
#include "BH.h"
using namespace std;

int main() {

  std::string decision;
  double mass, kai, mirr;
  BH* myBH;

  cout << "Welcome! Let's Build a Black Hole." << endl;
  cout << "Decide the parameters to build the Black Hole with :" << endl;
  cout << "0 : Mass \t 1 : Kai \t 2: Irr.Mass" <<endl;
  cout << "You can provide the Mass and/or Kai or any two of the three parameters (ex . 02)" << endl;

  cin >> decision;

  if (decision == "0") {
    cout << "Mass :";
    cin >> mass;
    myBH = new BH(BH::MassKai(mass));
  }
  else if (decision == "1"){
    cout << "Kai :";
    cin >> kai;
    myBH = new BH(BH::Kai(kai));
  }
  else if (decision == "01"){
    cout << "Mass :";
    cin >> mass;
    cout << "Kai : ";
    cin >> kai;
    myBH = new BH(BH::MassKai(mass, kai));
  }
  else if (decision == "02"){
    cout << "Mass : ";
    cin >> mass;
    cout << "Irr.Mass : ";
    cin >> mirr;
    myBH = new BH(BH::MassMirr(mass, mirr));
  }
  else if (decision == "12"){
    cout << "Kai : ";
    cin >> kai;
    cout << "Irr.Mass : ";
    cin >> mirr;
    myBH = new BH(BH::MirrKai(mirr, kai));
  }
  else{
    cout << "Error : Invalid choice!" << endl;
    return -1;
  }


  myBH->print();

  BBH* myBBH = new BBH(myBH->getMass(), myBH->getKai(), 0, myBH->getMass(), myBH->getKai(), 0);
  myBBH->print();

  delete myBH;
  delete myBBH;





  return 0;
}
