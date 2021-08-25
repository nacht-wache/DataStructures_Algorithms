#include <LIS_nlogn.cpp>
#include <gtest/gtest.h>

struct TestsFixture : testing::Test {
  std::vector<ll> result;
  std::vector<ll> answer;

  ~TestsFixture() override = default;
};

TEST_F(TestsFixture, arr1) {
  result = {5, 3, 4, 4, 2};
  result = Solution::foo(result);
  answer = {1, 3, 4, 5};

  for (size_t i{0}; i < result.size(); ++i) {
	EXPECT_EQ(result[i], answer[i]);
  }
  EXPECT_EQ(result.size(), answer.size());
}

TEST_F(TestsFixture, arr2) {
  result = {1};
  result = Solution::foo(result);
  answer = {1};

  for (size_t i{0}; i < result.size(); ++i) {
	EXPECT_EQ(result[i], answer[i]);
  }
  EXPECT_EQ(result.size(), answer.size());
}

TEST_F(TestsFixture, arr3) {
  result = {1, 2};
  result = Solution::foo(result);
  answer = {1};

  for (size_t i{0}; i < result.size(); ++i) {
	EXPECT_EQ(result[i], answer[i]);
  }
  EXPECT_EQ(result.size(), answer.size());
}

TEST_F(TestsFixture, arr4) {
  result = {2, 1};
  result = Solution::foo(result);
  answer = {1, 2};

  for (size_t i{0}; i < result.size(); ++i) {
	EXPECT_EQ(result[i], answer[i]);
  }
  EXPECT_EQ(result.size(), answer.size());
}

TEST_F(TestsFixture, arr5) {
  result = {1, 1};
  result = Solution::foo(result);
  answer = {1, 2};
  for (size_t i{0}; i < result.size(); ++i) {
	EXPECT_EQ(result[i], answer[i]);
  }
  EXPECT_EQ(result.size(), answer.size());
}

TEST_F(TestsFixture, arr6) {
  result = {9, 10, 6, 3, 6, 8, 7, 9, 6, 5};
  result = Solution::foo(result);
  answer = {1, 3, 5, 9, 10};
  for (size_t i{0}; i < result.size(); ++i) {
	EXPECT_EQ(result[i], answer[i]);
  }
  EXPECT_EQ(result.size(), answer.size());

}

TEST_F(TestsFixture, arr7) {
  result = {2, 3, 1, 2, 1, 3, 2, 1, 1, 2};
  result = Solution::foo(result);
  answer = {1, 3, 5, 8, 9};
  for (size_t i{0}; i < result.size(); ++i) {
	EXPECT_EQ(result[i], answer[i]);
  }
  EXPECT_EQ(result.size(), answer.size());
}

TEST_F(TestsFixture, arr8) {
  result =
	  {64, 80, 90, 69, 23, 78, 30, 76, 11, 2, 7, 42, 13, 45, 40, 52, 31, 42, 33, 74, 37, 64, 2, 26, 88, 51, 53, 95, 26,
	   7, 58, 9, 30, 29, 53, 69, 3, 71, 40, 89, 32, 90, 14, 49, 18, 70, 37, 79, 6, 48, 25, 28, 7, 81, 35, 99, 1, 1, 28,
	   17, 56, 77, 11, 64, 28, 6, 9, 62, 32, 2, 31, 29, 23, 50, 89, 95, 54, 36, 13, 52, 77, 58, 80, 58, 21, 20, 1, 82,
	   27, 31, 84, 14, 73, 55, 2, 69, 95, 33, 70, 72};
  // 90, 78, 76, 74, 64, 58, 53, 49, 48, 35, 32, 31, 29, 23, 21, 20, 14, 2
  result = Solution::foo(result);
  answer = {2, 6, 8, 20, 22, 27, 35, 39, 47, 55, 69, 71, 72, 73, 85, 86, 92, 95};
  for (size_t i{0}; i < result.size(); ++i) {
	EXPECT_EQ(result[i], answer[i]);
  }
  EXPECT_EQ(result.size(), answer.size());
}