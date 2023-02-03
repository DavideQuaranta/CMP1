#include <iostream>
#include "Matrices.h"

// Constructors
matrix::matrix(int Ncols, int Nrows, double *els){
	Ncols_ = Ncols;
	Nrows_ = Nrows;
	els_ = els;
}
matrix matrix::square(int N) {
	double els[N][N] = {0.};
	return matrix(N,N,*els);
}
matrix matrix::rect(int Ncols, int Nrows) {
	double els[Ncols][Nrows] = {0.};
	return matrix(Ncols,Nrows,*els);
}
matrix matrix::diag(int N, double *els) {

	double elements[N][N] = {0.};
	for(int i = 0; i < N; i++){
		elements[i][i] = els[i];
	}

	return matrix(N, N , *elements);
}
matrix::matrix(const matrix& OldMatrix){
	Ncols_ = OldMatrix.Ncols_;
	Nrows_ = OldMatrix.Nrows_;
	els_ = OldMatrix.els_;
}
matrix::~matrix(){
	cout << "~matrix() called" << endl;
}

// Getters
int matrix::getNcols() {
	return Ncols_;
}

int matrix::getNrows() {
	return Nrows_;
}

double matrix::getEls() {
	return *els_;
}

double* matrix::getCol(int i) {
	double* result = new double[Nrows_];
	for (int j = 0; j < Nrows_; j++) {

		result[j] = (*(els_ + j) + i);
	}
	return result;
}

double* matrix::getRow(int i) {
	double* result = new double[Ncols_];
	for(int j = 0; j < Ncols_; j++) {
		result[j] = (*(els_ + i) + j);
	}
	return result;
}

double matrix::getElement(int i, int j) {
	return (*(els_ + i) + j);
}

// Setters
void matrix::setNcols(int N) {
	Ncols_ = N;
}

void matrix::setNrows(int N) {
	Nrows_ = N;
}

void matrix::setEls(double *els) {
	els_ = els;
}

void matrix::setCol(int i, double *column) {
	for(int j = 0; j < Nrows_; j++) {
		*(els_ + j*Ncols_ + i) = column[j];
	}
}

void matrix::setRow(int i, double *row) {
	for(int j = 0; j < Ncols_; j++) {
		*(els_ + i*Ncols_ + j) = row[j];
	}
}

void matrix::setElement(int i, int j, double value) {
	*(els_ + i*Ncols_ + j) = value;
}

// Swappie methods
void matrix::swapRows(int i, int j){
	for(int k = 0; k < Ncols_; k++){
		double temp = *(els_ + i*Ncols_ + k);
		*(els_ + i*Ncols_ + k) = *(els_ + j*Ncols_ + k);
		*(els_ + j*Ncols_ + k) = temp;
	}
}

void matrix::swapCols(int i, int j){
	for(int k = 0; k < Nrows_; k++){
		double temp = *(els_ + k*Ncols_ + i);
		*(els_ + k*Ncols_ + i) = *(els_ + k*Ncols_ + j);
		*(els_ + k*Ncols_ + j) = temp;
}
}

void matrix::swapEls(int i1, int j1, int i2, int j2){
	double temp = *(els_ + i1*Ncols_ + j1);
	*(els_ + i1*Ncols_ + j1) = *(els_ + i2*Ncols_ + j2);
	*(els_ + i2*Ncols_ + j2) = temp;
}


void matrix::Transpose(){
	for(int i = 0; i < Nrows_; i++){
		for(int j = i; j < Ncols_; j++){
			double temp = *(els_ + i*Ncols_ + j);
			*(els_ + i*Ncols_ + j) = *(els_ + j*Ncols_ + i);
			*(els_ + j*Ncols_ + i) = temp;
		}
	}
}

void matrix::Print() {
	cout << "Let's print the matrix " << endl;
	cout << "" << endl;
	for (int i = 0; i < Ncols_; i++) {
		for (int j = 0; j < Nrows_; j++) {
			cout << "| " << *(els_ + i*Ncols_ + j) << " ";		}
		cout << " |" << endl;
	}
}
