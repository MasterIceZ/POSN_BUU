#include <iostream>
#include <vector>

inline void solve() {
	int n, m, q, x;
	std::cin >> n >> m >> q;
	std::vector<int> row(n + 1), col(m + 1);
	while(q--) {
		char t;
		std::cin >> t >> x;
		if(t == 'R') {
			row[x]++;
		}
		else {
			col[x]++;
		}
	}
	std::vector<int> cnt_row(2), cnt_col(2);
	for(int i=1; i<=n; ++i) {
		cnt_row[row[i] % 2]++;	
	}
	for(int i=1; i<=m; ++i) {
		cnt_col[col[i] % 2]++;
	}
	int answer = cnt_row[0] * cnt_col[1] + cnt_row[1] * cnt_col[0];
	std::cout << answer << "\n";
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
