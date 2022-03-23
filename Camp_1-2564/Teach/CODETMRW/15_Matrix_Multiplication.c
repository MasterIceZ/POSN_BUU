#include<stdio.h>
int a[15][15], b[15][15];
int main() {
	int n,m,r,c;
	scanf("%d %d %d %d", &n, &m, &r, &c);
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			scanf("%d", &a[i][j]);
	for(int i=0; i<r; ++i)
		for(int j=0; j<c; ++j)
			scanf("%d", &b[i][j]);
	if(m!=r) {
		printf("Can't Multiply.\n");
		return 0;
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<c; j++) {
			int ans=0;
			for(int k=0; k<m; k++)
				ans += a[i][k]*b[k][j];
			printf("%d ", ans);
		}
		printf("\n");
	}
	return 0;
}

