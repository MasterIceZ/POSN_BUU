#include<stdio.h>

int dp[100100];

int main() {
	int n, num;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &num);
		dp[i] = dp[i-1] + num;
	}
	int q, l, r;
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d", &l, &r);
		printf("%d\n", dp[r] - dp[l-1]);
	}
	return 0;
}
