#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int dp[333];

int32_t main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		int l, h, r;
		cin >> l >> h >> r;
		for(int j=l ;j<r; ++j){
			dp[j] = max(dp[j], h);
		}
	}
	int tmp = 0;
	for(int i=1; i<=255; ++i){
		if(dp[i]!=tmp){
			cout << i << " " << dp[i] << " ";
			tmp = dp[i];
		}
	}
	cout << endl;
	return 0;
}
