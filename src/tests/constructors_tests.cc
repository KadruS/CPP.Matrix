#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(Constructor, without_args) {
  S21Matrix matrix;

  EXPECT_EQ(matrix.GetRows(), 3);
  EXPECT_EQ(matrix.GetRows(), 3);
}

TEST(Constructor, with_args) {
  S21Matrix matrix(5, 5);

  EXPECT_EQ(matrix.GetRows(), 5);
  EXPECT_EQ(matrix.GetCols(), 5);
}

TEST(Constructor, copy) {
  S21Matrix m1(2, 2);

  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  S21Matrix m2(m1);

  EXPECT_TRUE(m1 == m2);
}

TEST(GetRows, basic) {
  S21Matrix m1(2, 2);

  EXPECT_EQ(m1.GetRows(), 2);
}

TEST(GetCols, basic) {
  S21Matrix m1(2, 2);

  EXPECT_EQ(m1.GetCols(), 2);
}

TEST(SetRows, lesser) {
  S21Matrix matrix1(3, 3);

  EXPECT_NO_THROW(matrix1.SetRows(2));
  EXPECT_EQ(matrix1.GetRows(), 2);
}

TEST(SetRows, greater) {
  S21Matrix matrix1(2, 2);

  EXPECT_NO_THROW(matrix1.SetRows(3));
  EXPECT_EQ(matrix1.GetRows(), 3);
  EXPECT_DOUBLE_EQ(matrix1(2, 0), 0);
  EXPECT_DOUBLE_EQ(matrix1(2, 1), 0);
}

TEST(SetCols, lesser) {
  S21Matrix matrix1(3, 3);

  EXPECT_NO_THROW(matrix1.SetCols(2));
  EXPECT_EQ(matrix1.GetCols(), 2);
}

TEST(SetCols, greater) {
  S21Matrix matrix1(2, 2);

  EXPECT_NO_THROW(matrix1.SetCols(3));
  EXPECT_EQ(matrix1.GetCols(), 3);
  EXPECT_DOUBLE_EQ(matrix1(0, 2), 0);
  EXPECT_DOUBLE_EQ(matrix1(1, 2), 0);
}
