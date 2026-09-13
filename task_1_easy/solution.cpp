#include <iostream>
#include <stack>


class Solution {
public:
	bool isValid(std::string s) {
		if (s.length() % 2 != 0) {
			return false;
		}
		std::stack<char> st;
		for (char ch : s) {
			if (ch == '{' || ch == '(' || ch == '[') {
				st.push(ch);
			}

			else {
				if (st.empty()) return false;

				char top = st.top();

				if (top == '(' && ch == ')' ||
					top == '{' && ch == '}' ||
					top == '[' && ch == ']')
				{
					st.pop();
				}
				else {
					return false;
				}
			}
		}
		return st.empty();
	}
};

int main() {
	Solution solution;
	// �������� �������
	std::cout << std::boolalpha;
	std::cout << "Test '()': " << solution.isValid("()") << "\n";
	std::cout << "Test '()[]{}': " << solution.isValid("()[]{}") << "\n";
	std::cout << "Test '(]': " << solution.isValid("(]") << "\n";
	std::cout << "Test '([)]': " << solution.isValid("([)]") << "\n";
	std::cout << "Test '{[]}': " << solution.isValid("{[]}") << "\n";
	std::cout << "Test '[': " << solution.isValid("[") << "\n";

	return 0;
}