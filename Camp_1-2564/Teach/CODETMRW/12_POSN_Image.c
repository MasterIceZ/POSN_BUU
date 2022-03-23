#include<stdio.h>

int main() {
	int q;
	scanf("%d", &q);
	while(q--) {
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(j==0 || i==n/2 || i==0 || (j==n-1&&i<=n/2)) printf("*");
				else printf("-");
			}
			printf("-");
			for(int j=0; j<n; j++) {
				if(j==0 || i==0 || j==n-1 || i==n-1) printf("*");
				else printf("-");
			}
			printf("-");
			for(int j=0; j<n; j++) {
				if(i==0 || i==n/2 || i==n-1 || (j==0&&i<=n/2) || (j==n-1&&i>=n/2)) printf("*");
				else printf("-");
			}
			printf("-");
			for(int j=0; j<n; j++) {
				if(j==0 || j==n-1 || i==j) printf("*");
				else printf("-");
			}
			printf("\n");
		}
	}
	return 0;
}

