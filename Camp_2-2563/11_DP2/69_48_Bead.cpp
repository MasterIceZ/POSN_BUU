/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 48_Bead
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
int a[111];
int dp[111][111][10];

int divide(int l, int r){
	if(l == r){
		dp[l][r][1] = a[l];
		return 0;
	}
	if(dp[l][r][1] != -1){
		return dp[l][r][0];
	}
	int nin = INT_MAX;
	for(int k=l; k<r; ++k){
		int now = divide(l, k) + divide(k+1, r) + (dp[l][k][1] * dp[k+1][r][1]);
		if(now < nin){
			nin = now;
			dp[l][r][1] = (dp[l][k][1] + dp[k+1][r][1])%100;
		}
	}
	return dp[l][r][0] = nin;
}

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << divide(1, n);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
		memset(dp, 0, sizeof dp);
		memset(a, 0, sizeof a);
	}
	return 0;
}
