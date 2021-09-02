#include <stairs.cpp>
#include <gtest/gtest.h>

struct Stairs : testing::Test {
  std::vector<int> A;
  int answer{};

  ~Stairs() override = default;
};

TEST_F(Stairs, test1) {
  A = {1, 2};
  answer = stairs(A);

  EXPECT_EQ(2, answer);
}

TEST_F(Stairs, test2) {
  A = {2, -1};
  answer = stairs(A);

  EXPECT_EQ(1, answer);
}

TEST_F(Stairs, test3) {
  A = {-1, 2, 1};
  answer = stairs(A);

  EXPECT_EQ(3, answer);
}

TEST_F(Stairs, test4) {
  A = {-2, -16, -13, -9, -48};
  answer = stairs(A);

  EXPECT_EQ(-63, answer);
}

TEST_F(Stairs, test5) {
  A = {1, 1, -2, -4, -6, 2, 2};
  answer = stairs(A);

  EXPECT_EQ(2, answer);
}

TEST_F(Stairs, test6) {
  A = {-64, -16, -13, -9, -48};
  answer = stairs(A);

  EXPECT_EQ(-73, answer);
}