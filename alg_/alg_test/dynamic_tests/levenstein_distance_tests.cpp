#include <levenstein_distance.cpp>
#include <gtest/gtest.h>

struct Levenstein : testing::Test {
  std::string str1;
  std::string str2;
  int answer{};

  ~Levenstein() override = default;
};

TEST_F(Levenstein, test1) {
  str1 = "ab";
  str2 = "ab";
  answer = get_levenshtein_distance(str1, str2);

  EXPECT_EQ(0, answer);
}

TEST_F(Levenstein, test2) {
  str1 = "short";
  str2 = "ports";
  answer = get_levenshtein_distance(str1, str2);

  EXPECT_EQ(3, answer);
}

TEST_F(Levenstein, test3) {
  str1 = "ports";
  str2 = "short";
  answer = get_levenshtein_distance(str1, str2);

  EXPECT_EQ(3, answer);
}

TEST_F(Levenstein, test4) {
  str1 = "editing";
  str2 = "distance";
  answer = get_levenshtein_distance(str1, str2);

  EXPECT_EQ(5, answer);
}

TEST_F(Levenstein, test5) {
  str1 = "distance";
  str2 = "editing";
  answer = get_levenshtein_distance(str1, str2);

  EXPECT_EQ(5, answer);
}