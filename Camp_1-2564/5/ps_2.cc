#include <bits/stdc++.h>
using namespace std;

const int MxN = 100010;
int a[MxN], dp[MxN];

void solve(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
		dp[i] = dp[i - 1] + a[i];
	}
	int sum_all = accumulate(a + 1, a + n + 1, 0);
	if(sum_all % 2){
		printf("NO");
		return ;
	}
	int middle = sum_all / 2;
	int current_sum = 0;
	// case 1
	for(int i=1; i<=n; ++i){
		current_sum += a[i];
		if(current_sum == middle){
			printf("%d", i);
			return ;
		}
	}
	// case 2
	for(int i=0; i<n; ++i){
		int idx = lower_bound(dp + 1, dp + n + 1, middle + dp[i]) - dp;
		if(dp[idx] == middle + dp[i]){
			printf("%d %d", i, idx);
			return ;
		}
	}
	printf("NO");
}

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		solve();
		printf("\n");
	}
	return 0;
}
