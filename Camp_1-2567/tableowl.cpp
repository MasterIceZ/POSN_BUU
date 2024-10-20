// TABLE OWL

#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

int a[MxN][MxN], dp[MxN][MxN];

signed main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> a[i][j];
		}
	}
	memset(dp, 0x3f, sizeof dp);
	for(int j=1; j<=m; ++j) {
		dp[1][j] = a[1][j];
	}
	for(int i=2; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			dp[i][j] = a[i][j] + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]});
		}
	}
	cout << *min_element(dp[n] + 1, dp[n] + m + 1) << "\n";
	return 0;
}
