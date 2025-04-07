#include <bits/stdc++.h>

using namespace std;

const int MxN = 77;

int a[MxN], dp[MxN][MxN * MxN];

inline void solve() {
	int n, k, l;
	cin >> n >> k >> l;
	l = min(l, n * n);
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	memset(dp, 0, sizeof dp);
	for(int i=1; i<=n; ++i) {
		for(int j=min(i, k); j>=1; --j) {
			for(int w=i-j; w<=l; ++w) {
				dp[j][w] = max(dp[j][w], a[i] + dp[j - 1][w + j - i]);
			}
		}
	}
	cout << *max_element(dp[k], dp[k] + l + 1) << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--) {
		solve();
	}
	return 0;
}
