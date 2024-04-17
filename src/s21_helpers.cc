#include "s21_matrix_oop.h"

void S21Matrix::PrintMatrix() {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      std::cout << this->GetMatrix()[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

void S21Matrix::FillMatrix(int m, int n) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      this->matrix_[i][j] = ++m + ++n;
    }
  }
}

void S21Matrix::SwapMatrix(S21Matrix& other) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
}

S21Matrix S21Matrix::CreateMinor(int row, int col) {
  //   S21Matrix * minor = new S21Matrix(A.GetRows() - 1, A.GetCols() - 1);

  // if (minor != NULL) {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0, minor_row = 0; i < rows_; ++i) {
    if (i != row) {
      for (int j = 0, minor_column = 0; j < cols_; ++j) {
        if (j != col) {
          minor(minor_row, minor_column) = (*this)(i, j);
          minor_column++;
        }
      }
      minor_row++;
    }
  }
  // }

  return minor;
}

void S21Matrix::SetRows(int rows) {
  S21Matrix result(rows, cols_);
  int less_rows = rows < rows_ ? rows : rows_;
  for (int i = 0; i < less_rows; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result(i, j) = matrix_[i][j];
    }
  }
  *this = result;
}

void S21Matrix::SetCols(int cols) {
  S21Matrix result(rows_, cols);
  int less_cols = cols < cols_ ? cols : cols_;
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < less_cols; ++j) {
      result(i, j) = matrix_[i][j];
    }
  }
  *this = result;
}