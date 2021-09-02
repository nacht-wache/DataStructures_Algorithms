#include <calculator.cpp>
#include <gtest/gtest.h>

struct Calculator : testing::Test {
  std::vector<int> answer;
  std::vector<int> expect;
  int n{};

  ~Calculator() override = default;
};

TEST_F(Calculator, test0) {
  expect = {1};
  n = 1;
  answer = calculator(n);

  for (int i{0}; i < answer.size(); ++i) {
	EXPECT_EQ(expect[i], answer[i]);
  }

  EXPECT_EQ(0, answer.size() - 1);
}

TEST_F(Calculator, test1) {
  expect = {1, 2, 4, 5};
  n = 5;
  answer = calculator(n);

  for (int i{0}; i < answer.size(); ++i) {
	EXPECT_EQ(expect[i], answer[i]);
  }

  EXPECT_EQ(3, answer.size() - 1);
}

TEST_F(Calculator, test2) {
  expect = {1, 3, 9, 10, 11, 22, 66, 198,
			594, 1782, 5346, 16038,
			16039, 32078, 96234};
  n = 96234;
  answer = calculator(n);

  for (int i{0}; i < answer.size(); ++i) {
	EXPECT_EQ(expect[i], answer[i]);
  }

  EXPECT_EQ(14, answer.size() - 1);
}

TEST_F(Calculator, test3) {
  expect = {1, 3, 9, 10};
  n = 10;
  answer = calculator(n);

  for (int i{0}; i < answer.size(); ++i) {
	EXPECT_EQ(expect[i], answer[i]);
  }

  EXPECT_EQ(3, answer.size() - 1);
}