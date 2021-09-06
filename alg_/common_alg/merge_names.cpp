#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::string;

vector<string> unique_names(const vector<string> &names1, const vector<string> &names2) {
  vector<string> answer;
  std::unordered_set<string> unique;
  for (auto &s : names1) {
	if (unique.find(s) == unique.end()) {
	  unique.insert(s);
	  answer.push_back(s);
	}
  }
  for (auto &s : names2) {
	if (unique.find(s) == unique.end()) {
	  unique.insert(s);
	  answer.push_back(s);
	}
  }
  return answer;
}



