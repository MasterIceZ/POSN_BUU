#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MxN = 50050;
int dp[MxN];

void gen(){
	for(int i=1; i<=MxN; ++i){
		dp[i] = i + dp[i-1];
	}
	return ;
}

void solve(){
	int n;
	cin >> n;
	int idx = lower_bound(dp+1, dp+MxN, n) - dp;
//	cout << idx;
	int now = n - dp[idx - 1];
	cout << now;
	return ;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	gen();
//	for(int i=1; i<5; ++i){
//		cout << dp[i] << " ";
//	}
//	cout << endl;
	int q;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}

	return 0;
}
