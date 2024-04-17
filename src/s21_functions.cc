#include "s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
  S21Matrix trans(this->cols_, this->rows_);
  for (int i = 0; i < this->cols_; ++i) {
    for (int j = 0; j < this->rows_; ++j) {
      trans.matrix_[i][j] = this->matrix_[j][i];
    }
  }
  return trans;
}

double S21Matrix::Determinant() {
  if (cols_ != rows_) {
    throw std::invalid_argument("Matrix is not square!");
  }
  double result = 0;
  if (this->rows_ == 1) {
    result = this->matrix_[0][0];
  } else if (this->rows_ == 2) {
    result = this->matrix_[0][0] * this->matrix_[1][1] -
             this->matrix_[1][0] * this->matrix_[0][1];
  } else if (this->rows_ > 2) {
    int sign = 1;
    for (int i = 0; i < this->cols_; ++i) {
      S21Matrix minor = this->CreateMinor(0, i);
      double minor_determinant = 0;

      minor_determinant = minor.Determinant();

      result += sign * (*this)(0, i) * minor_determinant;
      sign = -sign;
    }
  }

  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) {
    throw std::invalid_argument("Matrix is not square!");
  }
  S21Matrix result(rows_, cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      int sign = pow(-1, i + j);
      S21Matrix minor = this->CreateMinor(i, j);
      result(i, j) = sign * minor.Determinant();
    }
  }

  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) throw std::invalid_argument("Matrix is not square!");

  double determinant = this->Determinant();
  if (determinant == 0) throw std::logic_error("Determinant = 0!");

  S21Matrix result(rows_, cols_);

  if (rows_ == 1) {
    result(0, 0) = 1 / (*this)(0, 0);
  } else {
    S21Matrix complements = this->CalcComplements();
    S21Matrix trans = complements.Transpose();
    result = trans;
    result.MulNumber(1 / determinant);
  }

  return result;
}
