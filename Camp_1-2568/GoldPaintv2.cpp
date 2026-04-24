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
	// (i, j) -> row[i], cok[j]
	int answer = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if((row[i] + col[j]) % 2 == 1) {
				answer += 1;
			}
		}
	}
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
