#include "Conic.h"


int main() {

  float coeffs[6];

  //Showcase the baseclass
  cout << "\nInput the 6 coefficients for your Conic Section: \n";
  for(int i = 0; i < 6; i++){
    cout << "Coeff." << i+1 << " = ";
    cin >> coeffs[i];
  }
  ConicSection* myConic = new ConicSection(coeffs);
  std::cout << *myConic << std::endl;
  delete myConic;

  //resets coefficients array
  for(int i = 0; i < 6; i++){
    coeffs[i] = 0;
   }

  //Showcase the ellipse derived class
  cout << "\nInput the 2 coefficients for your Ellipse: \n";
  for(int i = 0; i < 2; i++){
    cout << "Coeff." << i+1 << " = ";
    cin >> coeffs[i];
  }
  ConicSection* myEllipse = new CanonicalEllipse(coeffs);
  std::cout << *myEllipse << std::endl;
  delete myEllipse;

  //Showcase the parabola derived class
  for(int i = 0; i < 6; i++){
    coeffs[i] = 0;
   }
  cout << "\nInput the 3 coefficients for your Parabola: \n";
  for(int i = 0; i < 3; i++){
    cout << "Coeff." << i+1 << " = ";
    cin >> coeffs[i];
  }
  CanonicalParabola* myParabola = new CanonicalParabola(coeffs);
  std::cout << *myParabola << std::endl;

  float x = 3;
  std::cout << "FirstDerivative in x = " << x << " : " << myParabola->FirstDerivative(x) << endl;
  std::cout << "SecondDerivative in x = " << x << " : " << myParabola->SecondDerivative(x) << endl;

  delete myParabola;

  //Showcase the hyperbola derived class
  for(int i = 0; i < 6; i++){
    coeffs[i] = 0;
   }
  cout << "\nInput the 2 coefficients for your Hyperbola: \n";
  for(int i = 0; i < 2; i++){
    cout << "Coeff." << i+1 << " = ";
    cin >> coeffs[i];
  }
  ConicSection* myHyperbola = new CanonicalHyperbola(coeffs);
  std::cout << *myHyperbola << std::endl;
  delete myHyperbola;



  return 0;
}
