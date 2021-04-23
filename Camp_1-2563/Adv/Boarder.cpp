#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[1111][1111];

int32_t main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=2*n+1; ++i){
		for(int j=1; j<=n+((i%2)+1)%2; ++j){
			cin >> a[i][j];
		}
	}
	vector<int>dp;
	for(int i=2; i<=2*n+1; i+=2){
		for(int j=1; j<=n; ++j){
			dp.push_back(3*(a[i-1][j] - a[i+1][j]) + 5*(a[i][j]-a[i][j+1]));
		}
	}
	int ans = 0;
	sort(dp.begin(), dp.end());
	for(int i=0; i<m; ++i){
		ans += dp[i];
	}
	cout << ans;
    return 0;
}
