#include <vector>
#include <cstdio>
#include <algorithm>

const int LEFT = -1;
const int POINT = 0;
const int RIGHT = 1;

struct Point {
  int x;
  int type;
  int index;

  Point(const int x, const int type, const int index)
	  : x(x), type(type), index(index) {}
};

void PointsAndSections() {
  int nRanges, nPoints;
  scanf("%d %d", &nRanges, &nPoints);
  std::vector<Point> points;
  for (int i{0}; i < nRanges; ++i) {
	int a, b;
	scanf("%d %d", &a, &b);
	points.emplace_back(std::min(a, b), LEFT, -1);
	points.emplace_back(std::max(a, b), RIGHT, -1);
  }
  std::vector<int> answer(nPoints, -1);
  for (int i{0}; i < nPoints; ++i) {
	int x;
	scanf("%d", &x);
	points.emplace_back(x, POINT, i);
  }
  std::sort(points.begin(), points.end(), [](const Point &left, const Point &right) {
	if (left.x != right.x) {
	  return left.x < right.x;
	} else {
	  return left.type < right.type;
	}
  });
  int cur = 0;
  for (auto p : points) {
	if (p.type == LEFT) {
	  ++cur;
	} else if (p.type == RIGHT) {
	  --cur;
	} else {
	  answer[p.index] = cur;
	}
  }

  for (int i = 0; i < nPoints; ++i) {
	if (i > 0) {
	  printf(" ");
	}
	printf("%d", answer[i]);
  }
}