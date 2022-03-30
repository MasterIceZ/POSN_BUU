#include <bits/stdc++.h>
using namespace std;

const int MxN = 1000010;
int dp[MxN];

signed main(){
	for(int i=2; i<=1000000; ++i){
		dp[i] = dp[i - 1] + 1;
		if(i % 2 == 0){
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if(i % 3 == 0){
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
	int q;
	scanf("%d", &q);
	while(q--){
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}
