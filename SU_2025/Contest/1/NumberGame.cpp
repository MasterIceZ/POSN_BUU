#include <bits/stdc++.h>

using namespace std;

const int MxN = 550;
const int INF = 1e9 + 100;

int a[MxN], dp[MxN][MxN];
// dp(l, r) = max(dp(l, x) + dp(x, r)) + a[l] + a[r]

int DP(int l, int r) {
	if(dp[l][r] != -1) {
		return dp[l][r];
	}
	if(r - l + 1 <= 2) {
		return dp[l][r] = 0;
	}
	dp[l][r] = -INF;
	for(int m=l+1; m<r; ++m) {
		dp[l][r] = max(dp[l][r], DP(l, m) + DP(m, r));
	}
	dp[l][r] += a[l] + a[r];
	return dp[l][r];
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << DP(1, n) << "\n";
	return 0;
}
