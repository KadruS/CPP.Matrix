#include "tests.h"

TEST(Sum, exception) {
  S21Matrix m1(3, 3);
  S21Matrix m2(2, 2);

  EXPECT_THROW(m1.SumMatrix(m2), std::invalid_argument);
  try {
    m1.SumMatrix(m2);
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(), "Different matrix dimensions!");
  }
}

TEST(Sum, 2x2) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 10;
  m1(1, 0) = 13.5;
  m1(0, 1) = -6;
  m1(1, 1) = 7;

  m2(0, 0) = 2;
  m2(1, 0) = 4;
  m2(0, 1) = 13;
  m2(1, 1) = 8;

  m1.SumMatrix(m2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 12);
  EXPECT_DOUBLE_EQ(m1(1, 0), 17.5);
  EXPECT_DOUBLE_EQ(m1(0, 1), 7);
  EXPECT_DOUBLE_EQ(m1(1, 1), 15);
}

TEST(Sub, exception) {
  S21Matrix m1(3, 3);
  S21Matrix m2(2, 3);

  EXPECT_THROW(m1.SubMatrix(m2), std::invalid_argument);
  try {
    m1.SubMatrix(m2);
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(), "Different matrix dimensions!");
  }
}

TEST(Sub, 2x2) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 10;
  m1(1, 0) = 13.5;
  m1(0, 1) = -6;
  m1(1, 1) = 7;

  m2(0, 0) = 2;
  m2(1, 0) = 4;
  m2(0, 1) = 13;
  m2(1, 1) = 8;

  m1.SubMatrix(m2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 8);
  EXPECT_DOUBLE_EQ(m1(1, 0), 9.5);
  EXPECT_DOUBLE_EQ(m1(0, 1), -19);
  EXPECT_DOUBLE_EQ(m1(1, 1), -1);
}

TEST(Equal, f) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 10;
  m1(1, 0) = 13.5;
  m1(0, 1) = -6;
  m1(1, 1) = 7;

  m2(0, 0) = 2;
  m2(1, 0) = 4;
  m2(0, 1) = 13;
  m2(1, 1) = 8;

  EXPECT_FALSE(m1.EqMatrix(m2));
}

TEST(Equal, t) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 10;
  m1(1, 0) = 13.5;
  m1(0, 1) = -6;
  m1(1, 1) = 7;

  m2(0, 0) = 10;
  m2(1, 0) = 13.5;
  m2(0, 1) = -6;
  m2(1, 1) = 7;

  EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(Equal, different_dimensions) {
  S21Matrix m1(3, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 10;
  m1(1, 0) = 13.5;
  m1(0, 1) = -6;
  m1(1, 1) = 7;

  m2(0, 0) = 10;
  m2(1, 0) = 13.5;
  m2(0, 1) = -6;
  m2(1, 1) = 7;

  EXPECT_FALSE(m1.EqMatrix(m2));
}

TEST(MulNumb, basic) {
  S21Matrix m1(2, 2);

  m1(0, 0) = 10;
  m1(1, 0) = 13.5;
  m1(0, 1) = -6;
  m1(1, 1) = 7;

  m1.MulNumber(2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 20);
  EXPECT_DOUBLE_EQ(m1(1, 0), 27);
  EXPECT_DOUBLE_EQ(m1(0, 1), -12);
  EXPECT_DOUBLE_EQ(m1(1, 1), 14);
}

TEST(MulMat, square) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 10;
  m1(0, 1) = -6;
  m1(1, 0) = 13.5;
  m1(1, 1) = 7;

  m2(0, 0) = 5;
  m2(0, 1) = 16;
  m2(1, 0) = -4;
  m2(1, 1) = 5;

  m1.MulMatrix(m2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 74);
  EXPECT_DOUBLE_EQ(m1(0, 1), 130);
  EXPECT_DOUBLE_EQ(m1(1, 0), 39.5);
  EXPECT_DOUBLE_EQ(m1(1, 1), 251);
}

TEST(MulMat, rect) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 3);

  m1(0, 0) = 10;
  m1(0, 1) = -6;
  m1(1, 0) = 13.5;
  m1(1, 1) = 7;

  m2(0, 0) = 5;
  m2(0, 1) = 16;
  m2(0, 2) = 4;
  m2(1, 0) = -4;
  m2(1, 1) = 5;
  m2(1, 2) = 6;

  m1.MulMatrix(m2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 74);
  EXPECT_DOUBLE_EQ(m1(0, 1), 130);
  EXPECT_DOUBLE_EQ(m1(1, 0), 39.5);
  EXPECT_DOUBLE_EQ(m1(1, 1), 251);
  EXPECT_DOUBLE_EQ(m1(0, 2), 4);
  EXPECT_DOUBLE_EQ(m1(1, 2), 96);
}

TEST(MulMat, exception) {
  S21Matrix m1(2, 2);
  S21Matrix m2(3, 2);

  m1(0, 0) = 10;
  m1(0, 1) = -6;
  m1(1, 0) = 13.5;
  m1(1, 1) = 7;

  m2(0, 0) = 5;
  m2(0, 1) = 16;
  m2(1, 0) = -4;
  m2(1, 1) = 5;

  EXPECT_THROW(m1.MulMatrix(m2), std::invalid_argument);
  try {
    m1.MulMatrix(m2);
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(),
                 "The number of columns of the first matrix is not equal to "
                 "the number of rows of the second matrix!");
  }
}
