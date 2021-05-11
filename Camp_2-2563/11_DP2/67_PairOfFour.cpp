/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Pair Of Four TOI10
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

int dp[11110][11110];

void solve(){
	cin >> n;
	vector<char>a(n);
	for(auto &x: a){
		cin >> x;
	}
	for(int sz=1; sz<n; ++sz){
		for(int i=0; i+sz<n; ++i){
			int j = i + sz;
			if(a[i] == a[j]){
				dp[i][j] = dp[i+1][j-1] + 1;
			}
			for(int k=0; k<j; ++k){
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
			}
		}
	}
	cout << dp[0][n-1];
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
