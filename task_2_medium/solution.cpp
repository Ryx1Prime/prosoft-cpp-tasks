#include <iostream>
#include <unordered_map>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		int left = 0;
		int max_len = 0;
		std::unordered_map<char, int> positions;
		for (int right = 0; right < s.length(); ++right) {
			char current_char = s[right];
			if (positions.find(current_char) != positions.end()) {
				if (positions[current_char] >= left) {
					left = positions[current_char] + 1;
				}
			}
			positions[current_char] = right;

			int current_len = right - left + 1;
			if (current_len > max_len) {
				max_len = current_len;
			}
		}
		return max_len;

	}
};

int main() {
	Solution solver;
	std::cout << "Test 'abcabcbb'(expect 3): " << solver.lengthOfLongestSubstring("abcabcbb") << "\n";
	std::cout << "Test 'bbbbb'(expect 1): " << solver.lengthOfLongestSubstring("bbbbb") << "\n";
	std::cout << "Test 'pwwkew'(expect 3): " << solver.lengthOfLongestSubstring("pwwkew") << "\n";
	std::cout << "Test ''(expect 0): " << solver.lengthOfLongestSubstring("") << "\n";
	std::cout << "Test 'abba'(expect 2): " << solver.lengthOfLongestSubstring("abba") << "\n";

	return 0;
}