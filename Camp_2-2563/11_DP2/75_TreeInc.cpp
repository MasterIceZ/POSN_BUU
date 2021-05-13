/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: treeinc
 * ALGO		: Dynamic Programming
 * DATE		: 11 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;

vector<int>g[333003];
int dp[300300];

void solve(){
	cin >> n;
	for(int i=1; i<n; ++i){
		int u, v;
		cin >> u >> v;
		g[max(u, v)].push_back(min(u, v));
	}
	int nax = -1;
	for(int i=1; i<=n; ++i){
		for(auto x: g[i]){
			dp[i] = max(dp[i], dp[x]);
		}
		dp[i]++;
		nax = max(nax, dp[i]);
	}
	cout << nax;
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
