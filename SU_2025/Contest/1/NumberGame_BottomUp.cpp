#include <bits/stdc++.h>

using namespace std;

const int MxN = 550;
const int INF = 1e9 + 100;

int a[MxN], dp[MxN][MxN];
// dp(l, r) = max(dp(l, x) + dp(x, r)) + a[l] + a[r]

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int sz=3; sz<=n; ++sz) {
		for(int l=1; l+sz-1<=n; ++l) {
			int r = l + sz - 1;
			dp[l][r] = -INF;
			for(int m=l+1; m<r; ++m) {
				int cur_val = dp[l][m] + dp[m][r] + a[l] + a[r];
				dp[l][r] = max(dp[l][r], cur_val);
			}		
		}
	}
	cout << dp[1][n];
	return 0;
}
