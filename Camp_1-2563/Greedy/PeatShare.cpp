#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int>dp(n+1);
	for(int i=1; i<=n; ++i){
		cin >> dp[i];
		dp[i] += dp[i-1];
	}
	if(dp[n]%2 == 1){
		cout << "NO" ;
		return ;
	}
	for(int i=1; i<=n; ++i){
		if(dp[n] - dp[i] == dp[i]){
			cout << i ;
			return ;
		}
	}
	for(int i=1; i<=n; ++i){
		if(dp[lower_bound(dp.begin()+1, dp.end(), dp[n]/2 + dp[i]) - dp.begin()] == dp[n/2] + dp[i]){
			cout << i << lower_bound(dp.begin()+1, dp.end(), dp[n]/2 - dp[i]) - dp.begin();
			return;
		}
	}
	return ;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}

	return 0;
}
