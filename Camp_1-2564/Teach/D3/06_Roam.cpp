#include<stdio.h>

int dp[100100];

int main() {
	int n, m, l, r;
	scanf("%d %d", &n, &m);
	while(m--) {
		scanf("%d %d", &l, &r);
		dp[l] += 1, dp[r+1] -= 1;
	}
	for(int i=1; i<=n; i++)
		dp[i] = dp[i-1] + dp[i];
	int q, x;
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &x);
		printf("%d\n", dp[x]);
	}
	return 0;
}
