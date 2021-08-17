#include <LIS_n^2.cpp>
#include <gtest/gtest.h>

struct BasicTestsFixture : testing::Test {
  std::vector<ll> check;
  ll var{0};

  BasicTestsFixture() {
	var = Solution::task({10, 9, 2, 5, 3, 7, 101, 18});
  }

  ~BasicTestsFixture() override = default;
};

TEST_F(BasicTestsFixture, Basic2TestsName) {
  EXPECT_EQ(4, var);
}