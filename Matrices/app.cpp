// app.cpp
#include <iostream>
#include "Matrices.h"
#include <algorithm>
#include <random>

int main(){

    int cols = 3, rows = 3;
    double mat[rows];

    for(int i=0;i<rows;i++){
      int num = rand();
      mat[i]=1;
    }

    matrix* myMatrix = new matrix(matrix::diag(rows, mat));

    myMatrix->Print();
    delete myMatrix;
    return 0;
}
