// Dataset.h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <math.h>
using namespace std;

class Dataset {
public:
  Dataset(int N, const string& filename);
  Dataset(int N, const std::vector<float>& vect);
  Dataset(const Dataset& OldDataset);
  void addPoint(int i, const float& newPoint);
  void delPoint(int i);
  Dataset operator+(const float& shift);
  void print();
  virtual ~Dataset();
  // virtual float mean() const = 0;

protected:
  int N_;
  std::vector<float> entries_;

};

class Arithmetic : public Dataset{
public:
  Arithmetic(int N, const string& filename);
  virtual ~Arithmetic();
  virtual float mean() const;
};

class Geometric : public Dataset{
public:
  Geometric(int N, const string& filename);
  virtual ~Geometric();
  virtual float mean() const;
};

class Harmonic : public Dataset{
public:
  Harmonic(int N, const string& filename);
  virtual ~Harmonic();
  virtual float mean() const;
};
