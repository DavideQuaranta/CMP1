#include <iostream>

using std::cout;
using std::endl;

class Datum {

  public:
    double value() { return value_; }
    double error() { return error_; }

  private:
    double value_;
    double error_;
};

int main() {

  Datum d1;
  cout << "d1.value(): " << d1.value() 
       << " d1.error(): " << d1.error()
       << endl;
  return 0;
}
