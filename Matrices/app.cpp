// app.cpp
#include <iostream>
#include "Matrices.h"
#include <algorithm>

int main(){

    int cols = 3, rows = 3;
    double mat[rows*cols] = {2.};
    double value = 2.;
    // std::fill_n(mat,rows*cols, value);

    matrix* myMatrix = new matrix(rows, cols, mat);

    myMatrix->Print();
    cout << *(myMatrix->getCol(0) + 1) <<endl;
    delete myMatrix;
    return 0;
}
