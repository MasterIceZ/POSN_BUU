#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int dp[1111][1111];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, l, r;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> dp[i][j];
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	int q;
	cin >> q;
	while(q--){
		int i, j, k, l;
		cin >> i >> j >> k >> l;
		i++, j++, k++, l++;
		cout << dp[k][l] - dp[i-1][l] - dp[k][j-1] + dp[i-1][j-1] << endl;
	}
	return 0;
}
