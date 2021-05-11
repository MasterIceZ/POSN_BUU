/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Coin Change Min
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

int coin[1010], dp[1001000];

void solve(){
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		cin >> coin[i];
	}
	dp[0] = 0;
	for(int i=1; i<=m; ++i){
		dp[i] = INT_MAX;
		for(int j=0; j<n; ++j){
			if(i - coin[j] >= 0){
				dp[i] = min(dp[i], 1 + dp[i-coin[j]]);
			}
		}
	}
	cout << (dp[m]==INT_MAX?0:dp[m]);
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
