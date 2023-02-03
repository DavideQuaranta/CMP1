#ifndef Datum_h
#define Datum_h

#include <iostream>

class Datum {
  public:
    Datum();
    Datum(double x, double y);
    Datum(const Datum& datum);
    ~Datum() { };

    double value() const { return value_; }
    double error() const { return error_; }
    double significance() const;
    void print() const;

    Datum operator+( const Datum& rhs ) const;
    const Datum& operator+=( const Datum& rhs );

    Datum sum( const Datum& rhs ) const;

    const Datum& operator=( const Datum& rhs );

    bool operator<(const Datum& rhs) const;

    Datum operator*( const Datum& rhs ) const;
    Datum operator/( const Datum& rhs ) const;

    Datum operator*( const double& rhs ) const;

  private:
    double value_;
    double error_;
};
Datum operator*(const double& lhs, const Datum& rhs);
Datum productDoubleDatum(const double& lhs, const Datum& rhs);
std::ostream& operator<<(std::ostream& os, const Datum& rhs);
#endif
