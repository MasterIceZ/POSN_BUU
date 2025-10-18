#include <iostream>
#include <queue>
#include <string>

inline void solve() {
	std::string s;
	int k, cnt = 0, res = 0;
	std::cin >> s >> k;
	std::queue<char> q;
	for(int i=0; i<static_cast<int> (s.size()); ++i) {
		q.emplace(s[i]);
		cnt += (s[i] == 'B');	
		while(cnt > k) {
			cnt -= (q.front() == 'B');
			q.pop();
		}
		res = std::max(res, static_cast<int> (q.size()));
	}
	std::cout << res << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int q;
	std::cin >> q;
	while(q--) {
		solve();
	}
	return 0;
}
