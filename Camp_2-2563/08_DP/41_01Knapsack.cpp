/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 0/1 Knapsack
 * ALGO		: Dynamic Programming
 * DATE		: 9 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
int dp[10010][10010];

void solve(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		int v, w;
		cin >> v >> w;
		for(int j=1; j<w; ++j){
			dp[i][j] = dp[i-1][j];
		}
		for(int j=w; j<=m; ++j){
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
		}
	}
	cout << dp[n][m];
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
