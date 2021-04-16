#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> dp(n+1);
	for(int i=1; i<=n; ++i){
		cin >> dp[i];
		dp[i] += dp[i-1];
	}
	int q, l, r;
	cin >> q;
	while(q--){
		cin >> l >> r;
		cout << dp[r] - dp[l-1] << endl;
	}

	return 0;
}
