#include <iostream>
#include <stack>
#include <string>

inline void calculate(char a, char b) {
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->ios::sync_with_stdio(false);
	std::string s;
	std::cin >> s;
	std::stack<int> operator_stk, operand_stk;
	for(auto c: s) {
		if(isalpha(c)) {
			operand_stk.emplace(20);
		}
		else if(c == '[') {
			operator_stk.emplace(-1);
		}
		else if(c == ']') {
			while(!operator_stk.empty() && operator_stk.top() != -1) {
				int current_opeator = oprator_stk.top();
				opeator_stk.pop();
				calculate();
			}
			operator_stk.pop();
		}
		else {
			while(!operand_stk.empty() && ) {

			}
		}
	}

	return 0;
}
