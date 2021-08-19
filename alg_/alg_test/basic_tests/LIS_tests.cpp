#include <LIS_nlogn.cpp>
#include <gtest/gtest.h>

struct TestsFixture : testing::Test {
  std::vector<ll> check;

  ll var{0};

  ~TestsFixture() override = default;
};

TEST_F(TestsFixture, arr1) {
  check = {5, 3, 4, 4, 2};
  check = Solution::foo(check);
  EXPECT_EQ(check[0], 1);
  EXPECT_EQ(check[1], 3);
  EXPECT_EQ(check[2], 4);
  EXPECT_EQ(check[3], 5);
  EXPECT_EQ(check.size(), 4);
}

TEST_F(TestsFixture, arr2) {
  check = {1};
  check = Solution::foo(check);

  EXPECT_EQ(check[0], 1);
  EXPECT_EQ(check.size(), 1);
}

TEST_F(TestsFixture, arr3) {
  check = {1, 2};
  check = Solution::foo(check);

  EXPECT_EQ(check[0], 2);
  EXPECT_EQ(check.size(), 1);
}

TEST_F(TestsFixture, arr4) {
  check = {2, 1};
  check = Solution::foo(check);

  EXPECT_EQ(check[0], 1);
  EXPECT_EQ(check[1], 2);
  EXPECT_EQ(check.size(), 2);
}



TEST_F(TestsFixture, arr5) {
  check = {1, 1};
  check = Solution::foo(check);

  EXPECT_EQ(check[0], 1);
  EXPECT_EQ(check[1], 2);
  EXPECT_EQ(check.size(), 2);
}

TEST_F(TestsFixture, arr6) {
  check = {9, 10, 6, 3, 6, 8, 7, 9, 6, 5};
  check = Solution::foo(check);

  EXPECT_EQ(check[0], 2);
  EXPECT_EQ(check[1], 6);
  EXPECT_EQ(check[2], 7);
  EXPECT_EQ(check[3], 9);
  EXPECT_EQ(check[4], 10);

  EXPECT_EQ(check.size(), 5);
}

TEST_F(TestsFixture, arr7) {
  check = {2, 3, 1, 2, 1, 3, 2, 1, 1, 2};
  check = Solution::foo(check);

  EXPECT_EQ(check[0], 2);
  EXPECT_EQ(check[1], 6);
  EXPECT_EQ(check[2], 7);
  EXPECT_EQ(check[3], 8);
  EXPECT_EQ(check[4], 9);
  EXPECT_EQ(check[5], 10);

  EXPECT_EQ(check.size(), 6);
}