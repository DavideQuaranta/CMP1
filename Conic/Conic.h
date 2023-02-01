// Conic.h
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class ConicSection {
  public:
    ConicSection();
    ConicSection(float *params);
    ConicSection(const ConicSection& conic);
    virtual ~ConicSection();

    float getCoeff(int i) const;
    void setCoeff (int i, float newcoeff);
    float discriminant() const;

    friend ostream& operator<<(ostream& os, const ConicSection& conic);


  protected:
    float coeff_[6];
    int type_;
    int findType() {
      {
        if(this->discriminant() < 0){
          return 0;
        }
        else if(this->discriminant() == 0){
          return 1;
        }

        else if(this->discriminant() > 0){
          return 2;
        }
        else{return -1;}
      }
    }

};

class CanonicalEllipse : public ConicSection{
public:
  CanonicalEllipse(float *params);
  virtual ~CanonicalEllipse();
};

class CanonicalParabola : public ConicSection{
public:
  CanonicalParabola(float *params);
  virtual ~CanonicalParabola();
  float FirstDerivative(const float& x);
  float SecondDerivative(const float& x);
};

class CanonicalHyperbola : public ConicSection{
public:
  CanonicalHyperbola(float *params);
  virtual ~CanonicalHyperbola();
};
