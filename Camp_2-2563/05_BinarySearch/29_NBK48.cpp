/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: NBK48
 * ALGO		: Binary Search + Dynamic Programming
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

int dp[100100];

void solve(){
	cin >> m;
	int ans = upper_bound(dp+1, dp+n+1, m) - dp - 1;
	cout << ans;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	cin >> n >> t;
	for(int i=1; i<=n; ++i){
		cin >> dp[i];
		dp[i] += dp[i-1];
	}	
	for(int i=n-1; i>=1; --i){
		dp[i] = min(dp[i], dp[i+1]);
	}
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
