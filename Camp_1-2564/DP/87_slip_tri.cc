#include <bits/stdc++.h>
using namespace std;

const int MxN = 1010;
int dp[MxN][MxN];

signed main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=i; ++j){
			scanf("%d", &dp[i][j]);
		}
	}
	for(int i=n-1; i>=1; --i){
		for(int j=1; j<=i; ++j){
			dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}
	printf("%d\n", dp[1][1]);
	return 0;
}
