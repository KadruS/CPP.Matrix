#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  matrix_ = new double *[rows_];
  matrix_[0] = new double[rows_ * cols_];

  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = matrix_[0] + (cols_ * i);
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = 0;
    }
  }
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument("Rows or columns can't be less than 1!");
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double *[rows_];
  matrix_[0] = new double[rows_ * cols_];

  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = matrix_[0] + (cols_ * i);
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = 0;
    }
  }
}

// Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(new double *[rows_]) {
  matrix_[0] = new double[rows_ * cols_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = matrix_[0] + (cols_ * i);
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

// Конструктор перемещения
S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  delete[] matrix_[0];
  delete[] matrix_;
}