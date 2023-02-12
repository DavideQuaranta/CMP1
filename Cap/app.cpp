// app.cpp
#include "Capacitor.h"
#include <iostream>
using namespace std;

int main() {

  double Q,U,R1,R2,epsr,dV;
  int decision;

  //SHowcase of Capacitor Class
  cout << "\nThis program builds Spherical Capacitors!\n" << endl;
  cout << "Provide R1 : ";
  cin >> R1;
  cout << "Provide R2 : ";
  cin >> R2;
  cout << "Provide eps_r : ";
  cin >> epsr;

  cout << "\nNow you have to choose what parameter to input." << endl;
  cout << "Charge (0) \t Energy (1) \t Voltage (2)" << endl;
  cin >> decision;

  if(decision == 0){
    cout << "Input the Charge :";
    cin >> Q;
    Capacitor* myCapacitor = new Capacitor(Capacitor::Q(Q, R1, R2, epsr));
    myCapacitor->print();
    delete myCapacitor;
  }
  else if(decision == 1){
    cout << "Input the Energy :";
    cin >> U;
    Capacitor* myCapacitor = new Capacitor(Capacitor::U(U, R1, R2, epsr));
    myCapacitor->print();
    delete myCapacitor;
  }
  else if(decision == 2){
    cout << "Input the Voltage :";
    cin >> dV;
    Capacitor* myCapacitor = new Capacitor(Capacitor::dV(dV, R1, R2, epsr));
    myCapacitor->print();
    delete myCapacitor;
  }
  else{
    cout << "Error : Invalid choice!" << endl;
    return -1;
  }

  //Showcase of class CompositeCapacitor

  std::vector<double> epsr_array;
  int N;
  cout << "\nNow let's build a composite Capacitor!\n" << endl;
  cout << "How many layers (N) : ";
  cin >> N;
  cout << "Input N the values of the layer epsr : ";

  for(int i = 0; i<N; i++){
    double temp;
    cin >> temp;
    epsr_array.push_back(temp);
  }

  CompositeCapacitor* myCapacitor = new CompositeCapacitor(CompositeCapacitor::Q(Q, R1, R2, epsr_array));
  myCapacitor->print();
  delete myCapacitor;


  return 0;
}
