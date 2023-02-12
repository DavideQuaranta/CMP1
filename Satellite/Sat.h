//Sat.h

class Planet{
public:
  Planet();
  Planet(double R, double mass, double G);
  double Mass();
  double G();
private:
  double R_ ; //km
  double mass_; //kg
  double G_ ;
};

class Atmosphere{
public:
  Atmosphere(double h, double F10, double Ap);
  void seth(double h);
private:
  double h_;
  double rho_;
  double F10_;
  double Ap_;
};

class Satellite{
public:
  Satellite(double *x, double *v, double A, double Cd, double mass);
  double mass();
  double A();
  double Cd();
  double x(int i);
  double v(int i);
private:
  double x_[3];
  double v_[3];
  double mass_;
  double A_, Cd_;
};

class FlySatellite{
public:
  FlySatellite(Planet planet, Atmosphere atmo, Satellite sat);
  virtual void simulation(double t, double dt) const = 0;
protected:
  Planet planet_;
  Atmosphere atmo_;
  Satellite sat_;

};

class Euler : public FlySatellite{
public:
  Euler(Planet planet, Atmosphere atmo, Satellite sat) : FlySatellite(planet,atmo,sat){}
  virtual void simulation(double t, double dt);
};


class RungeKutta2 : public FlySatellite{
public:
  RungeKutta2(Planet planet, Atmosphere atmo, Satellite sat) : FlySatellite(planet,atmo,sat){}
  virtual void simulation(double t, double dt);
};
