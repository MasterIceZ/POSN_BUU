#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

	int q;
	std::cin >> q;
	while(q--) {
		std::string s;
		int k, cnt_b = 0, answer = 0;
		std::cin >> s >> k;
		std::queue<char> qu;
		for(auto c: s) {
			qu.push(c);
			if(c == 'B') {
				cnt_b += 1;
			}
			while(cnt_b > k) {
				if(qu.front() == 'B') {
					cnt_b -= 1;
				}
				qu.pop();
			}
			answer = std::max(answer, (int) qu.size());
		}
		std::cout << answer << "\n";
	}

	return 0;
}
