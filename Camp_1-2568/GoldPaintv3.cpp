#include <iostream>
#include <vector>

void solve() {
	int n, m, k, x;
	std::cin >> n >> m >> k;
	std::vector<int> row(n + 1), col(m + 1);
	while(k--) {
		char t;
		std::cin >> t >> x;
		if(t == 'R') {
			row[x]++;
		}
		else {
			col[x]++;
		}
	}
	std::vector<int> row_cnt(2), col_cnt(2);
	for(int i=1; i<=n; ++i) {
		row_cnt[row[i] % 2] += 1;
	}
	for(int i=1; i<=m; ++i) {
		col_cnt[col[i] % 2] += 1;
	}
	int answer = row_cnt[1] * col_cnt[0] + row_cnt[0] * col_cnt[1];
	std::cout << answer << "\n";
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
