#include "tests.h"

TEST(Transpose, square) {
  S21Matrix m1(2, 2);

  m1(0, 0) = 10;
  m1(0, 1) = -6;
  m1(1, 0) = 13.5;
  m1(1, 1) = 7;

  S21Matrix m2 = m1.Transpose();

  EXPECT_DOUBLE_EQ(m2(0, 0), 10);
  EXPECT_DOUBLE_EQ(m2(0, 1), 13.5);
  EXPECT_DOUBLE_EQ(m2(1, 0), -6);
  EXPECT_DOUBLE_EQ(m2(1, 1), 7);
}

TEST(Transpose, rect) {
  S21Matrix m1(2, 3);

  m1(0, 0) = 10;
  m1(0, 1) = -6;
  m1(0, 2) = 1;
  m1(1, 0) = 13.5;
  m1(1, 1) = 7;
  m1(1, 2) = 2;

  S21Matrix m2 = m1.Transpose();

  EXPECT_DOUBLE_EQ(m2(0, 0), 10);
  EXPECT_DOUBLE_EQ(m2(0, 1), 13.5);
  EXPECT_DOUBLE_EQ(m2(1, 0), -6);
  EXPECT_DOUBLE_EQ(m2(1, 1), 7);
  EXPECT_DOUBLE_EQ(m2(2, 0), 1);
  EXPECT_DOUBLE_EQ(m2(2, 1), 2);
}

TEST(CreateMinor, 3x3) {
  S21Matrix m1(3, 3);

  m1(0, 0) = 10;
  m1(0, 1) = -6;
  m1(0, 2) = 1;
  m1(1, 0) = 13.5;
  m1(1, 1) = 7;
  m1(1, 2) = 2;
  m1(2, 0) = 5;
  m1(2, 1) = 5;
  m1(2, 2) = 4;

  S21Matrix m2 = m1.CreateMinor(0, 2);

  EXPECT_DOUBLE_EQ(m2(0, 0), 13.5);
  EXPECT_DOUBLE_EQ(m2(0, 1), 7);
  EXPECT_DOUBLE_EQ(m2(1, 0), 5);
  EXPECT_DOUBLE_EQ(m2(1, 1), 5);
}

TEST(Determinant, 1x1) {
  S21Matrix m1(1, 1);

  m1(0, 0) = 10;

  double det = m1.Determinant();

  EXPECT_DOUBLE_EQ(det, 10);
}

TEST(Determinant, 2x2) {
  S21Matrix m1(2, 2);

  m1(0, 0) = 10;
  m1(0, 1) = -6;
  m1(1, 0) = 13.5;
  m1(1, 1) = 7;

  double det = m1.Determinant();

  EXPECT_DOUBLE_EQ(det, 151);
}

TEST(Determinant, 3x3) {
  S21Matrix m1(3, 3);

  m1(0, 0) = 10;
  m1(0, 1) = -6;
  m1(0, 2) = 1;
  m1(1, 0) = 13.5;
  m1(1, 1) = 7;
  m1(1, 2) = 2;
  m1(2, 0) = 5;
  m1(2, 1) = 5;
  m1(2, 2) = 4;

  double det = m1.Determinant();

  EXPECT_DOUBLE_EQ(det, 476.5);
}

TEST(Determinant, exception) {
  S21Matrix m1(2, 3);

  m1(0, 0) = 10;
  m1(0, 1) = -6;
  m1(0, 2) = 1;
  m1(1, 0) = 13.5;
  m1(1, 1) = 7;
  m1(1, 2) = 2;

  EXPECT_THROW(m1.Determinant(), std::invalid_argument);
  try {
    double det = m1.Determinant();
    std::cout << det << std::endl;
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(), "Matrix is not square!");
  }
}

TEST(CalcComponents, exception) {
  S21Matrix m1(2, 3);

  m1(0, 0) = 10;
  m1(0, 1) = -6;
  m1(0, 2) = 1;
  m1(1, 0) = 13.5;
  m1(1, 1) = 7;
  m1(1, 2) = 2;

  EXPECT_THROW(m1.CalcComplements(), std::invalid_argument);
  try {
    S21Matrix m2 = m1.CalcComplements();
    std::cout << m2(0, 1) << std::endl;
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(), "Matrix is not square!");
  }
}

TEST(CalcComponents, 3x3) {
  S21Matrix m1(3, 3);

  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(0, 2) = 3;
  m1(1, 0) = 0;
  m1(1, 1) = 4;
  m1(1, 2) = 2;
  m1(2, 0) = 5;
  m1(2, 1) = 2;
  m1(2, 2) = 1;

  S21Matrix m2 = m1.CalcComplements();

  EXPECT_DOUBLE_EQ(m2(0, 0), 0);
  EXPECT_DOUBLE_EQ(m2(0, 1), 10);
  EXPECT_DOUBLE_EQ(m2(0, 2), -20);
  EXPECT_DOUBLE_EQ(m2(1, 0), 4);
  EXPECT_DOUBLE_EQ(m2(1, 1), -14);
  EXPECT_DOUBLE_EQ(m2(1, 2), 8);
  EXPECT_DOUBLE_EQ(m2(2, 0), -8);
  EXPECT_DOUBLE_EQ(m2(2, 1), -2);
  EXPECT_DOUBLE_EQ(m2(2, 2), 4);
}

TEST(CalcComponents, 3x3_2) {
  S21Matrix m1(3, 3);

  m1(0, 0) = 33;
  m1(0, 1) = 7;
  m1(0, 2) = 23;
  m1(1, 0) = 0;
  m1(1, 1) = 12;
  m1(1, 2) = 2;
  m1(2, 0) = 8;
  m1(2, 1) = 12;
  m1(2, 2) = 19;

  S21Matrix m2 = m1.CalcComplements();

  EXPECT_DOUBLE_EQ(m2(0, 0), 204);
  EXPECT_DOUBLE_EQ(m2(0, 1), 16);
  EXPECT_DOUBLE_EQ(m2(0, 2), -96);
  EXPECT_DOUBLE_EQ(m2(1, 0), 143);
  EXPECT_DOUBLE_EQ(m2(1, 1), 443);
  EXPECT_DOUBLE_EQ(m2(1, 2), -340);
  EXPECT_DOUBLE_EQ(m2(2, 0), -262);
  EXPECT_DOUBLE_EQ(m2(2, 1), -66);
  EXPECT_DOUBLE_EQ(m2(2, 2), 396);
}

TEST(Inverse, exception_square) {
  S21Matrix m1(2, 3);

  m1(0, 0) = 10;
  m1(0, 1) = -6;
  m1(0, 2) = 1;
  m1(1, 0) = 13.5;
  m1(1, 1) = 7;
  m1(1, 2) = 2;

  EXPECT_THROW(m1.CalcComplements(), std::invalid_argument);
  try {
    S21Matrix m2 = m1.CalcComplements();
    std::cout << m2(0, 1) << std::endl;
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(), "Matrix is not square!");
  }
}

TEST(Inverse, exception_determinant) {
  S21Matrix m1(3, 3);

  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(0, 2) = 3;
  m1(1, 0) = 4;
  m1(1, 1) = 5;
  m1(1, 2) = 6;
  m1(2, 0) = 1;
  m1(2, 1) = 2;
  m1(2, 2) = 3;

  EXPECT_THROW(m1.InverseMatrix(), std::logic_error);
  try {
    S21Matrix m2 = m1.InverseMatrix();
    std::cout << m2(0, 1) << std::endl;
  } catch (const std::logic_error& e) {
    EXPECT_STREQ(e.what(), "Determinant = 0!");
  }
}

TEST(Inverse, 3x3_1) {
  S21Matrix m1(3, 3);

  m1(0, 0) = 23;
  m1(0, 1) = 12;
  m1(0, 2) = 7;
  m1(1, 0) = 5;
  m1(1, 1) = 9;
  m1(1, 2) = 1;
  m1(2, 0) = 4;
  m1(2, 1) = 11;
  m1(2, 2) = 0;

  S21Matrix m2 = m1.InverseMatrix();

  EXPECT_DOUBLE_EQ(m2(0, 0), (double)11 / 72);
  EXPECT_DOUBLE_EQ(m2(0, 1), (double)-77 / 72);
  EXPECT_DOUBLE_EQ(m2(0, 2), (double)17 / 24);
  EXPECT_DOUBLE_EQ(m2(1, 0), (double)-1 / 18);
  EXPECT_DOUBLE_EQ(m2(1, 1), (double)7 / 18);
  EXPECT_DOUBLE_EQ(m2(1, 2), (double)-1 / 6);
  EXPECT_DOUBLE_EQ(m2(2, 0), (double)-19 / 72);
  EXPECT_DOUBLE_EQ(m2(2, 1), (double)205 / 72);
  EXPECT_DOUBLE_EQ(m2(2, 2), (double)-49 / 24);
}

TEST(Inverse, 3x3_2) {
  S21Matrix m1(3, 3);

  m1(0, 0) = 2;
  m1(0, 1) = 5;
  m1(0, 2) = 7;
  m1(1, 0) = 6;
  m1(1, 1) = 3;
  m1(1, 2) = 4;
  m1(2, 0) = 5;
  m1(2, 1) = -2;
  m1(2, 2) = -3;

  S21Matrix m2 = m1.InverseMatrix();

  EXPECT_DOUBLE_EQ(m2(0, 0), 1);
  EXPECT_DOUBLE_EQ(m2(0, 1), -1);
  EXPECT_DOUBLE_EQ(m2(0, 2), 1);
  EXPECT_DOUBLE_EQ(m2(1, 0), -38);
  EXPECT_DOUBLE_EQ(m2(1, 1), 41);
  EXPECT_DOUBLE_EQ(m2(1, 2), -34);
  EXPECT_DOUBLE_EQ(m2(2, 0), 27);
  EXPECT_DOUBLE_EQ(m2(2, 1), -29);
  EXPECT_DOUBLE_EQ(m2(2, 2), 24);
}
