#include "s21_matrix_oop.h"

S21Matrix operator+(const S21Matrix& matrix_1, const S21Matrix& matrix_2) {
  S21Matrix result(matrix_1);
  result.SumMatrix(matrix_2);
  return result;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix operator-(const S21Matrix& matrix_1, const S21Matrix& matrix_2) {
  S21Matrix result(matrix_1);
  result.SubMatrix(matrix_2);
  return result;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix operator*(const S21Matrix& matrix_1, const S21Matrix& matrix_2) {
  S21Matrix result(matrix_1);
  result.MulMatrix(matrix_2);
  return result;
}

S21Matrix operator*(const S21Matrix& matrix, const double& num) {
  S21Matrix result(matrix);
  result.MulNumber(num);
  return result;
}

S21Matrix operator*(const double& num, const S21Matrix& matrix) {
  return matrix * num;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double& num) {
  MulNumber(num);
  return *this;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  S21Matrix(other).SwapMatrix(*this);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

double& S21Matrix::operator()(int i, int j) {
  if (i > rows_ - 1 || j > cols_ - 1) {
    throw std::out_of_range("Out of matrix range!");
  }
  return matrix_[i][j];
}
