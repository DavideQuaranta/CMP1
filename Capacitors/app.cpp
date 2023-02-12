//app.cpp
#include "Capacitors.h"
#include <iostream>
using namespace std;

int main() {
  Capacitor myCap = Capacitor(1);

  Capacitor myCap2 = myCap || myCap;
  myCap2.print();

  return 0;
}
