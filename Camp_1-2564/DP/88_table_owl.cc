#include <bits/stdc++.h>
using namespace std;

const int MxN = 505;
int dp[MxN][MxN], answer = INT_MAX;

signed main(){
	int n, m;
	scanf("%d %d", &n, &m);
	memset(dp, 0x3f, sizeof dp);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			scanf("%d", &dp[i][j]);
		}
	}
	for(int i=n-1; i>=1; --i){
		for(int j=1; j<=m; ++j){
			dp[i][j] += min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]});
		}
	}
	for(int i=1; i<=m; ++i){
		answer = min(answer, dp[1][i]);
	}
	printf("%d\n", answer);
	return 0;
}
