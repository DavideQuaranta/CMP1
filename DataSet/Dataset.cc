//Dataset.cc
#include "Dataset.h"

Dataset::Dataset(int N, const string& filename){
  ifstream infile(filename);
  string line;
  float val;

  N_ = N;

  while(!infile.eof()) {
    getline(infile,line);
    if( line == "\n" || line == "" ) continue;
    sscanf(line.c_str(),"%f", &val);
    entries_.push_back(val);
  }
  infile.close();

}
Dataset::Dataset(int N, const std::vector<float>& vect){
  N_ = N;
  entries_ = vect;
}
Dataset::Dataset(const Dataset& OldDataset){
  N_ = OldDataset.N_;
  entries_ = OldDataset.entries_;
}

void Dataset::addPoint(int i,const float& newPoint){
  entries_.insert(entries_.begin() + i - 1, newPoint);
  N_ += 1;
}
void Dataset::delPoint(int i){
  entries_.erase(entries_.begin() + i - 1);
  N_ -= 1;
}

Dataset Dataset::operator+(const float& shift){
  std::vector<float> newvect;
  newvect = entries_;
  std::for_each(newvect.begin(), newvect.end(), [shift](float& x){ x += shift; });
  return Dataset(N_, newvect);
}
void Dataset::print(){
  cout << "\nYour Dataset: \n" << endl;
  for(int i = 0; i < N_; i++){
    cout << i+1 <<". " << entries_[i] << endl;
  }
}
Dataset::~Dataset(){
  cout << "~Dataset() called." << endl;
}

Arithmetic::Arithmetic(int N, const string& filename) : Dataset(N, filename){}
Arithmetic::~Arithmetic(){
  cout << "~Arithmetic() called." << endl;
}
float Arithmetic::mean() const {
  int i=0;
  float sum = 0;
  for(float itr : entries_) {
    sum += itr;
    i++;
  }
  return sum/N_;
}

Geometric::Geometric(int N, const string& filename) : Dataset(N, filename){}
Geometric::~Geometric(){
  cout << "~Geometric() called." << endl;
}
float Geometric::mean() const {
  int i=0;
  float sum = 1;
  for(float itr : entries_) {
    // cout <<itr<<endl;
    sum *= itr;
    i++;
  }
  return pow(sum, 1./N_);
}

Harmonic::Harmonic(int N, const string& filename) : Dataset(N, filename){}
Harmonic::~Harmonic(){
  cout << "~Harmonic() called." << endl;
}
float Harmonic::mean() const {
  int i=0;
  float sum = 0;
  for(float itr : entries_) {
    sum += 1/itr;
    i++;
  }
  return N_/sum;
}
