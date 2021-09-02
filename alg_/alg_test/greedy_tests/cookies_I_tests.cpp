#include <cookies_I.cpp>
#include <gtest/gtest.h>

struct Cookies : testing::Test {
  int answer{};
  int expect{};

  ~Cookies() override = default;
};

TEST_F(Cookies, test0) {
  expect = 5;
  std::vector<int> kids = {3, 4, 5, 6, 1, 2, 3};
  std::vector<int> cookies = {1, 2, 3, 1, 2, 4, 5};
  answer = Solution::findContentChildren(kids, cookies);
  EXPECT_EQ(expect, answer);
}

TEST_F(Cookies, test1) {
  expect = 13;
  std::vector<int> kids = {1, 2, 3, 345, 32, 4, 134, 13, 432, 52, 4, 23, 5, 21, 5123, 4, 32, 41};
  std::vector<int> cookies = {234, 1235, 23, 51, 325, 1, 2, 1, 4, 213, 123, 5412, 52, 4132};
  answer = Solution::findContentChildren(kids, cookies);
  EXPECT_EQ(expect, answer);
}
