#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, l, r;
	cin >> n >> m;
	vector<int> dp(n+1);
	for(int i=0; i<m; ++i){
		cin >> l >> r;
		dp[l]++;
		dp[r+1]--;
	}
	for(int i=1; i<=n; ++i){
		dp[i] += dp[i-1];
	}
	int q, x;
	cin >> q;
	while(q--){
		cin >> x;
		cout << dp[x] << endl;
	}

	return 0;
}
