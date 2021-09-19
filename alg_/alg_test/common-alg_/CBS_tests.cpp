#include <CBS.cpp>
#include <gtest/gtest.h>

struct CBS_tests : testing::Test {
  Solution instance;
  std::string task{};
  int result{};
  int expected{};

  ~CBS_tests() override = default;
};

TEST_F(CBS_tests, fixture_1) {
  task = "[]";
  result = instance.solve(task);
  expected = 0;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_2) {
  task = "{}[]";
  result = instance.solve(task);
  expected = 0;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_3) {
  task = "[()]";
  result = instance.solve(task);
  expected = 0;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_4) {
  task = "(())";
  result = instance.solve(task);
  expected = 0;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_5) {
  task = "{[]}()";
  result = instance.solve(task);
  expected = 0;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_6) {
  task = "{";
  result = instance.solve(task);
  expected = 1;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_7) {
  task = "{[}";
  result = instance.solve(task);
  expected = 3;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_8) {
  task = "foo(bar);";
  result = instance.solve(task);
  expected = 0;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_9) {
  task = "foo(bar[i);";
  result = instance.solve(task);
  expected = 10;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_10) {
  task = "{{{[][][]";
  result = instance.solve(task);
  expected = 3;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_11) {
  task = "{*{{}";
  result = instance.solve(task);
  expected = 3;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_12) {
  task = "{*}";
  result = instance.solve(task);
  expected = 0;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_13) {
  task = "{{";
  result = instance.solve(task);
  expected = 2;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_14) {
  task = "";
  result = instance.solve(task);
  expected = 0;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_15) {
  task = "{{{**[][][]";
  result = instance.solve(task);
  expected = 3;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_16) {
  task = "{{[()]]";
  result = instance.solve(task);
  expected = 7;

  EXPECT_EQ(result, expected);
}

TEST_F(CBS_tests, fixture_17) {
  task = "[]([]";
  result = instance.solve(task);
  expected = 3;

  EXPECT_EQ(result, expected);
}
