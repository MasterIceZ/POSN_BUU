// GOLD PAINT

#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

int row_cnt[MxN], col_cnt[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--) {
		int n, m, k, x;
		cin >> n >> m >> k;
		while(k--) {
			char t;
			cin >> t >> x;
			if(t == 'R') {
				row_cnt[x]++;
			}
			else {
				col_cnt[x]++;
			}
		}
		int answer = 0;
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=m; ++j) {
				answer += (row_cnt[i] + col_cnt[j]) % 2;
			}
		}
		cout << answer << "\n";
		for(int i=1; i<=n; ++i) {
			row_cnt[i] = 0;
		}
		for(int j=1; j<=m; ++j) {
			col_cnt[j] = 0;
		}
	}
	return 0;
}
