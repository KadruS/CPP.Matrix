#include "tests.h"

TEST(Parentheses, basic) {
  S21Matrix m1(3, 3);

  m1(1, 1) = 25;

  EXPECT_DOUBLE_EQ(m1.GetMatrix()[1][1], 25);
}

TEST(Parentheses, exception) {
  S21Matrix m1(3, 3);

  EXPECT_THROW(m1(3, 1) = 25, std::out_of_range);
  try {
    m1(3, 1) = 25;
  } catch (const std::out_of_range& e) {
    EXPECT_STREQ(e.what(), "Out of matrix range!");
  }
}

TEST(AssignOp, basic) {
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

  m1 = m2;

  EXPECT_DOUBLE_EQ(m1(0, 0), 5);
  EXPECT_DOUBLE_EQ(m1(0, 1), 16);
  EXPECT_DOUBLE_EQ(m1(1, 0), -4);
  EXPECT_DOUBLE_EQ(m1(1, 1), 5);
  EXPECT_DOUBLE_EQ(m1(0, 2), 4);
  EXPECT_DOUBLE_EQ(m1(1, 2), 6);
}

TEST(AssignOp, self) {
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

  m2 = m2;
  m1 = m2;

  EXPECT_DOUBLE_EQ(m2(0, 0), 5);
  EXPECT_DOUBLE_EQ(m2(0, 1), 16);
  EXPECT_DOUBLE_EQ(m2(1, 0), -4);
  EXPECT_DOUBLE_EQ(m2(1, 1), 5);
  EXPECT_DOUBLE_EQ(m2(0, 2), 4);
  EXPECT_DOUBLE_EQ(m2(1, 2), 6);
}

TEST(EqualOp, f) {
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

  EXPECT_FALSE(m1 == m2);
}

TEST(EqualOp, t) {
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

  EXPECT_TRUE(m1 == m2);
}

TEST(EqualOp, different_dimensions) {
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

  EXPECT_FALSE(m1 == m2);
}

TEST(Plus, exception) {
  S21Matrix m1(3, 3);
  S21Matrix m2(2, 2);

  EXPECT_THROW(m1 + m2, std::invalid_argument);
  try {
    m1 + m2;
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(), "Different matrix dimensions!");
  }
}

TEST(Plus, 2x2) {
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

  S21Matrix m3 = m1 + m2;

  EXPECT_DOUBLE_EQ(m3(0, 0), 12);
  EXPECT_DOUBLE_EQ(m3(1, 0), 17.5);
  EXPECT_DOUBLE_EQ(m3(0, 1), 7);
  EXPECT_DOUBLE_EQ(m3(1, 1), 15);
}

TEST(Plus_assign, exception) {
  S21Matrix m1(3, 3);
  S21Matrix m2(2, 2);

  EXPECT_THROW(m1 += m2, std::invalid_argument);
  try {
    m1 += m2;
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(), "Different matrix dimensions!");
  }
}

TEST(Plus_assign, 2x2) {
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

  m1 += m2;

  EXPECT_DOUBLE_EQ(m1(0, 0), 12);
  EXPECT_DOUBLE_EQ(m1(1, 0), 17.5);
  EXPECT_DOUBLE_EQ(m1(0, 1), 7);
  EXPECT_DOUBLE_EQ(m1(1, 1), 15);
}

TEST(Minus, exception) {
  S21Matrix m1(3, 3);
  S21Matrix m2(2, 3);

  EXPECT_THROW(m1 - m2, std::invalid_argument);
  try {
    m1 - m2;
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(), "Different matrix dimensions!");
  }
}

TEST(Minus, 2x2) {
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

  S21Matrix m3 = m1 - m2;

  EXPECT_DOUBLE_EQ(m3(0, 0), 8);
  EXPECT_DOUBLE_EQ(m3(1, 0), 9.5);
  EXPECT_DOUBLE_EQ(m3(0, 1), -19);
  EXPECT_DOUBLE_EQ(m3(1, 1), -1);
}

TEST(Minus_assign, exception) {
  S21Matrix m1(3, 3);
  S21Matrix m2(2, 3);

  EXPECT_THROW(m1 -= m2, std::invalid_argument);
  try {
    m1 -= m2;
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(), "Different matrix dimensions!");
  }
}

TEST(Minus_assign, 2x2) {
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

  m1 -= m2;

  EXPECT_DOUBLE_EQ(m1(0, 0), 8);
  EXPECT_DOUBLE_EQ(m1(1, 0), 9.5);
  EXPECT_DOUBLE_EQ(m1(0, 1), -19);
  EXPECT_DOUBLE_EQ(m1(1, 1), -1);
}

TEST(MulOpNumb, basic) {
  S21Matrix m1(2, 2);

  m1(0, 0) = 10;
  m1(1, 0) = 13.5;
  m1(0, 1) = -6;
  m1(1, 1) = 7;

  S21Matrix m3 = m1 * 2;

  EXPECT_DOUBLE_EQ(m3(0, 0), 20);
  EXPECT_DOUBLE_EQ(m3(1, 0), 27);
  EXPECT_DOUBLE_EQ(m3(0, 1), -12);
  EXPECT_DOUBLE_EQ(m3(1, 1), 14);
}

TEST(MulOpNumb, reverse) {
  S21Matrix m1(2, 2);

  m1(0, 0) = 10;
  m1(1, 0) = 13.5;
  m1(0, 1) = -6;
  m1(1, 1) = 7;

  S21Matrix m3 = 2 * m1;

  EXPECT_DOUBLE_EQ(m3(0, 0), 20);
  EXPECT_DOUBLE_EQ(m3(1, 0), 27);
  EXPECT_DOUBLE_EQ(m3(0, 1), -12);
  EXPECT_DOUBLE_EQ(m3(1, 1), 14);
}

TEST(MulOpMat, square) {
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

  S21Matrix m3 = m1 * m2;

  EXPECT_DOUBLE_EQ(m3(0, 0), 74);
  EXPECT_DOUBLE_EQ(m3(0, 1), 130);
  EXPECT_DOUBLE_EQ(m3(1, 0), 39.5);
  EXPECT_DOUBLE_EQ(m3(1, 1), 251);
}

TEST(MulOpMat, rect) {
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

  S21Matrix m3 = m1 * m2;

  EXPECT_DOUBLE_EQ(m3(0, 0), 74);
  EXPECT_DOUBLE_EQ(m3(0, 1), 130);
  EXPECT_DOUBLE_EQ(m3(1, 0), 39.5);
  EXPECT_DOUBLE_EQ(m3(1, 1), 251);
  EXPECT_DOUBLE_EQ(m3(0, 2), 4);
  EXPECT_DOUBLE_EQ(m3(1, 2), 96);
}

TEST(MulOpMat, exception) {
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

  EXPECT_THROW(m1 * m2, std::invalid_argument);
  try {
    m1* m2;
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(),
                 "The number of columns of the first matrix is not equal to "
                 "the number of rows of the second matrix!");
  }
}

TEST(MulOp_assignNumb, basic) {
  S21Matrix m1(2, 2);

  m1(0, 0) = 10;
  m1(1, 0) = 13.5;
  m1(0, 1) = -6;
  m1(1, 1) = 7;

  m1 *= 2;

  EXPECT_DOUBLE_EQ(m1(0, 0), 20);
  EXPECT_DOUBLE_EQ(m1(1, 0), 27);
  EXPECT_DOUBLE_EQ(m1(0, 1), -12);
  EXPECT_DOUBLE_EQ(m1(1, 1), 14);
}

TEST(MulOp_assignMat, square) {
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

  m1 *= m2;

  EXPECT_DOUBLE_EQ(m1(0, 0), 74);
  EXPECT_DOUBLE_EQ(m1(0, 1), 130);
  EXPECT_DOUBLE_EQ(m1(1, 0), 39.5);
  EXPECT_DOUBLE_EQ(m1(1, 1), 251);
}

TEST(MulOp_assignMat, rect) {
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

  m1 *= m2;

  EXPECT_DOUBLE_EQ(m1(0, 0), 74);
  EXPECT_DOUBLE_EQ(m1(0, 1), 130);
  EXPECT_DOUBLE_EQ(m1(1, 0), 39.5);
  EXPECT_DOUBLE_EQ(m1(1, 1), 251);
  EXPECT_DOUBLE_EQ(m1(0, 2), 4);
  EXPECT_DOUBLE_EQ(m1(1, 2), 96);
}

TEST(MulOp_assignMat, exception) {
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

  EXPECT_THROW(m1 *= m2, std::invalid_argument);
  try {
    m1 *= m2;
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ(e.what(),
                 "The number of columns of the first matrix is not equal to "
                 "the number of rows of the second matrix!");
  }
}
