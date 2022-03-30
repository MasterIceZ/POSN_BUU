#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6 + 10;
int dp[MxN];

signed main(){
	int n, maxx = INT_MIN;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%d", &dp[i]);
	}
	for(int i=n; i>=1; --i){
		maxx = max(maxx, dp[i]);
		if(dp[i] <= maxx){
			dp[i] = maxx - dp[i];
		}
	}
	maxx = -1;
	for(int i=1; i<=n; ++i){
		maxx = max(maxx, dp[i]);
	}
	printf("%d\n", maxx);
	return 0;
}
