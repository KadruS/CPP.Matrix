#pragma once
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);

  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;

  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  // Accessors
  double** GetMatrix() { return matrix_; }
  int GetRows() const { return rows_; }
  int GetCols() const { return cols_; }

  // Mutators
  void SetRows(int rows);
  void SetCols(int cols);

  // Helpers
  void PrintMatrix();
  S21Matrix CreateMinor(int, int);
  void FillMatrix(int m = 1, int n = 1);
  void SwapMatrix(S21Matrix& other);

  // Operators
  friend S21Matrix operator+(const S21Matrix&, const S21Matrix&);
  S21Matrix& operator+=(const S21Matrix&);

  friend S21Matrix operator-(const S21Matrix&, const S21Matrix&);
  S21Matrix& operator-=(const S21Matrix&);

  friend S21Matrix operator*(const S21Matrix&, const S21Matrix&);
  friend S21Matrix operator*(const S21Matrix&, const double&);
  friend S21Matrix operator*(const double&, const S21Matrix&);
  S21Matrix& operator*=(const S21Matrix&);
  S21Matrix& operator*=(const double&);

  S21Matrix& operator=(const S21Matrix&);
  bool operator==(const S21Matrix&);

  double& operator()(int, int);
};
