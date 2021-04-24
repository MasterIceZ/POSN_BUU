#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int n, m;

void solve(){
	cin >> n;
	vector<int>dp(n+1);
	for(int i=1; i<=n; ++i){
		cin >> dp[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=i; j>=1; --j){
			dp[i] = max(dp[i], dp[j] + dp[i-j]);
		}
	}	
	cout << dp[n];
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}

	return 0;
}
