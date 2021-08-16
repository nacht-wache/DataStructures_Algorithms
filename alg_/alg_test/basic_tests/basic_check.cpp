#include <task.hpp>
#include <gtest/gtest.h>

struct BasicTestsFixture : testing::Test {
  std::vector<ll> check;

  BasicTestsFixture() {
    check = task(5, 0, 1, 2 ,3 , 4);
  }

  ~BasicTestsFixture() = default;
};

TEST_F(BasicTestsFixture, BasicTestsName) {
  for(ll i = 1; i < 6; ++i) {
	EXPECT_EQ(i, check[i]);
  }
}