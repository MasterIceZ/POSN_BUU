#include<stdio.h>

int C[2][10010];
int main() {
	int n,r,mod;
	scanf("%d %d %d", &n, &r, &mod);
	C[0][0] = C[1][0] = C[1][1] = 1%mod;
	for(int i=2; i<=n; i++) {
		for(int j=0; j<=i; j++)
			C[i%2][j] = (C[(i+1)%2][j] + C[(i+1)%2][j-1])%mod;
	}
	printf("%d\n", C[n%2][r]);
	return 0;
}
