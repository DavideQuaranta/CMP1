//Capacitor.h
#define eps0  8.854e-12 // F/m
#define pi 3.14
#include <vector>

class Capacitor{
public:
  static Capacitor Q(double Q, double R1, double R2, double epsr);
  static Capacitor dV(double dV, double R1, double R2, double epsr);
  static Capacitor U(double U, double R1, double R2, double epsr);
  ~Capacitor();

  double getQ();
  double getC();
  double getU();
  double getdV();
  void print();


protected:
  double Q_, U_, C_, dV_;
  Capacitor(double Q, double dV, double U, double C){
    Q_ = Q;
    dV_ = dV;
    U_ = U;
    C_ = C;
  };
};



class CompositeCapacitor : public Capacitor{
public:
  static CompositeCapacitor Q(double Q, double R1, double R2, std::vector<double> epsr);
  static CompositeCapacitor dV(double dV, double R1, double R2, std::vector<double> epsr);
  static CompositeCapacitor U(double U, double R1, double R2, std::vector<double> epsr);
  ~CompositeCapacitor();

private:
  std::vector<double> epsr_;
  CompositeCapacitor(double Q, double dV, double U, double C, std::vector<double> epsr);
};
