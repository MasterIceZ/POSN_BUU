#include <algorithm>
#include <iostream>
#include <queue>

int main(int argc, char *argv[]) {
	std::string s;
	int k, count_zeros = 0, max_consec_ones = 0;
	std::cin >> s >> k;
	std::queue<char> q;
	for(auto x: s) {
		if(x == '1') {
			q.emplace(x);
		}
		else {
			while(!q.empty() && count_zeros >= k) {
				if(q.front() == '0') {
					count_zeros--;
				}
				q.pop();
			}
			count_zeros++;
			q.emplace(x);
		}
		max_consec_ones = std::max(max_consec_ones, (int) q.size());
	}
	std::cout << max_consec_ones << "\n";
	return 0;
}
