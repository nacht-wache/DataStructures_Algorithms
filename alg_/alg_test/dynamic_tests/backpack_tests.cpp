#include "../../dynamic/backpack.cpp"
#include <gtest/gtest.h>

struct Backpack : testing::Test {
  int answer{};

  ~Backpack() override = default;
};

TEST_F(Backpack, test0) {
  int S = 10;
  std::vector<int> weight = {1, 4, 8};
  answer = backpack(S, weight);
  EXPECT_EQ(9, answer);
}

TEST_F(Backpack, test1) {
  int S = 14;
  std::vector<int> weight = {3, 4, 5, 8};
  answer = backpack(S, weight);
  EXPECT_EQ(13, answer);
}

TEST_F(Backpack, test2) {
  int S = 139;
  std::vector<int> weight = {2, 3, 4, 8, 10, 20, 100};
  answer = backpack(S, weight);
  EXPECT_EQ(139, answer);
}