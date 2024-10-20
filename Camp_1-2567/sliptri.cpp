// SLIP TRIANGLE

#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

int a[MxN][MxN], dp[MxN][MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=i; ++j) {
			cin >> a[i][j];
		}
	}
	memset(dp, -0x3f, sizeof dp);
	dp[1][1] = a[1][1];
	for(int i=2; i<=n; ++i) {
		for(int j=1; j<=i; ++j) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
		}
	}
	cout << *max_element(dp[n] + 1, dp[n] + n + 1) << "\n";
	return 0;
}
