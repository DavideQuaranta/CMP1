#ifndef MCINTEGRATOR_H
#define MCINTEGRATOR_H

#include "Integrator.h"

class MCIntegrator : public Integrator {

  public:
    MCIntegrator(int n=1000);
    void setNPoints( int n ) {
        npoints_ = n;
    }
    virtual double integrate(double xlo, double xhi) const;

  private:
    int npoints_;
    double uniform(double a, double b) const;

};
#endif
