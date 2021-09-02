#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using std::priority_queue;
using std::vector;
using std::string;
using std::unordered_map;

struct stl_solution {
  static unordered_map<char, string> encode(const string &text);
  static string decode(const unordered_map<string, char> &huffman_codes);
  static unordered_map<string, char> create_table();

 private:
  struct HuffmanNode {
	string data{};
	int count{};

	HuffmanNode() = default;
	HuffmanNode(string data, int count)
		: data(std::move(data)), count(count) {}
	HuffmanNode(const HuffmanNode &) = default;
	HuffmanNode &operator=(const HuffmanNode &) = default;
	HuffmanNode(HuffmanNode &&node) = default;

	HuffmanNode &operator=(HuffmanNode &&node) = default;

	bool operator<(const HuffmanNode &other) const {
	  return std::tie(count, data) > std::tie(other.count, other.data);
	}
  };
};

unordered_map<char, string> stl_solution::encode(const string &text) {
  // get the frequency count of each letter
  unordered_map<char, int> ch_frequency;
  for (char c : text) {
	++ch_frequency[c];
  }
  // create a vector of frequencies
  std::vector<HuffmanNode> frequencies;
  frequencies.reserve(ch_frequency.size());
  for (auto &entry : ch_frequency) {
	frequencies.emplace_back(string(1, entry.first), entry.second);
  }
  if (frequencies.size() == 1) {
	unordered_map<char, string> result;
	result[frequencies[0].data[0]] = "0";
	return result;
  }

  priority_queue<HuffmanNode> huffman_table(frequencies.begin(), frequencies.end());
  unordered_map<char, string> result;
  while (huffman_table.size() >= 2) {
	// pull the lowest
	auto low1 = huffman_table.top();
	huffman_table.pop();

	auto low2 = huffman_table.top();
	huffman_table.pop();

	//add to left node 0 and to right node 1
	for (char ch : low1.data) {
	  result[ch] += "0";
	}

	for (char ch : low2.data) {
	  result[ch] += "1";
	}

	// combine the two entries and reinsert into the table
	huffman_table.push({low1.data + low2.data, low1.count + low2.count});
  }

  for (auto &[key, value] : result) {
	std::reverse(value.begin(), value.end());
  }
  return result;
}

unordered_map<string, char> stl_solution::create_table() {
  size_t letter_count, string_size;
  std::cin >> letter_count >> string_size;

  unordered_map<string, char> huffman_codes;
  for (size_t i{0}; i < letter_count; ++i) {
	char ch, delimit;
	string binary_code;
	std::cin >> ch >> delimit >> binary_code;
	huffman_codes[binary_code] = ch;
  }
  return huffman_codes;
}

string stl_solution::decode(const unordered_map<string, char> &huffman_codes) {
  string binary_string;
  std::cin >> binary_string;
  string result;

  string code;
  for (auto ch : binary_string) {
	code += ch;
	auto it = huffman_codes.find(code);
	if (it != huffman_codes.end()) {
	  result += it->second;
	  code = "";
	}
  }
  return result;
}
