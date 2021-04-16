#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int dp[3][100100];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, k;
	cin >> n >> r >> k;
	if( n < 2){
		cout << (1%k);
		return 0;
	}
	dp[1][0] = dp[1][1] = 1;
	for(int i=2; i<=n; ++i){
		dp[i%2][0] = dp[i%2][i] = 1;
		for(int j=1; j<i; ++j){
			dp[i%2][j] = (dp[(i+1)%2][j] + dp[(i+1)%2][j-1])%k;
		}
	}
	cout << dp[n%2][r]%k;
	return 0;
}
