#include<bits/stdc++.h>
using namespace std;

int dp[555][555], a[555][555];
int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >>a[i][j];
		}
	}
	for(int i=1; i<=m; ++i){
		dp[1][i] = a[1][i];
	}
	for(int i=2; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(j == 1){
				dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + a[i][j];
			}
			else if(j == m){
				dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
			}
			else{
				dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]}) + a[i][j];
			}
		}
	}
//	for(int i=1; i<=n; ++i){
//		for(int j=1; j<=m; ++j){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	int ans = INT_MAX;
	for(int i=1; i<=m; ++i){
		ans = min(ans, dp[n][i]);
	}
	cout << ans << endl;
	return 0;
}
