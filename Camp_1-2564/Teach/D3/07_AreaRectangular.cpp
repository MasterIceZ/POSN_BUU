#include<stdio.h>

int dp[1010][1010];
int main() {
	int r, c, num;
	scanf("%d %d", &r, &c);
	for(int i=1; i<=r; i++) {
		for(int j=1; j<=c; j++) {
			scanf("%d", &num);
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + num;
		}
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		++x1, ++x2, ++y1, ++y2;
		int ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
		printf("%d\n", ans);
	}
	return 0;
}
