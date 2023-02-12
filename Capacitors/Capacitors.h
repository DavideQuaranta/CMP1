// Capacitors.h
#define eps0 8.854e-12

class Capacitor{
public:
  Capacitor(double Capacitance);
  Capacitor(double Area, double d, double eps);
  Capacitor(const Capacitor& OldCapacitor);
  void setCapacitance(double newcap);
  double getCapacitance();
  void print();

  Capacitor operator+(const Capacitor& SecondCapacitor);
  Capacitor operator||(const Capacitor& SecondCapacitor);

private:
  double C_;
};
