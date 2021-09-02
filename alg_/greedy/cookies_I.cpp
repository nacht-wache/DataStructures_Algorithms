#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  static int findContentChildren(vector<int> &kids, vector<int> &cookies) {
	int ans{0};
	sort(kids.begin(), kids.end());
	sort(cookies.begin(), cookies.end());
	size_t kid_i = 0;
	for (int sz : cookies) {
	  if (kid_i == kids.size())
		return ans;
	  if (sz >= kids[kid_i]) {
		++ans;
		++kid_i;
	  }
	}
	return ans;
  }
};