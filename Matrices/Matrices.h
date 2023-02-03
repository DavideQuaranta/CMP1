#include <iostream>
using namespace std;

class matrix{
  public:
    // Constructors
    matrix(int Ncols, int Nrows, double *els);
    static matrix square(int N);
    static matrix rect(int Nrows, int Ncols);
    static matrix diag(int N, double *els);
	matrix(const matrix& OldMatrix);

    // Destructor
    ~matrix();

    // Getters for attributes
    int getNcols();
    int getNrows();
    double getEls();

    // Getters for column, row and element
    double* getCol(int i);
    double* getRow(int i);
    double getElement(int i, int j);

    // Setters for attributes
    void setNcols(int N);
    void setNrows(int N);
    void setEls(double *els);

    // Setters for column, row and element
    void setCol(int i, double *column);
    void setRow(int i, double *row);
    void setElement(int i, int j, double value);

    // Swap methods
    void swapRows(int i, int j);
    void swapCols(int i, int j);
    void swapEls(int i1, int j1, int i2, int j2);

    // Transpose method
    void Transpose();

    // Print
    void Print();


  private:
	int Ncols_, Nrows_;
	double* els_;
};
