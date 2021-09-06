#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;

class Solution {
 public:
  static vector<int> TwoSum(const std::vector<int> &arr, int target) {
	unordered_map<int, int> value_index;
	for (int i{0}; i < arr.size(); ++i) {
	  auto it = value_index.find(target - arr[i]);
	  if (it != value_index.end()) {
		return {it->second, i};
	  }
	  value_index[arr[i]] = i;
	}
	throw std::invalid_argument("sum doesn't exist");
  }
};
