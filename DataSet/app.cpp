//app.cpp
#include <random>
#include "Dataset.h"

int main() {

  int N = 10;
  float randomNumber;
  ofstream outfile;
  outfile.open ("output.txt");

  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_real_distribution<double>  distr(0, 10);

  for(int i = 0; i < N; i++){
    randomNumber = distr(generator);
    if(randomNumber == 0){
      randomNumber = distr(generator);
    }
    outfile << randomNumber << endl;
  }
  outfile.close();

  Harmonic* dataset = new Harmonic(N, "output.txt");
  dataset->print();
  std::cout << "The mean is : " << dataset->mean() << endl;
  cout<<"\n"<<endl;



  delete dataset;
  return 0;
}
