#include<stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		n=2*n+1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(i==0 || i==n-1 || j==0 || j==n-1) printf("*");
				else if(i%2==0 && j<=i) printf("*");
				else if(j%2==0 && i<=j) printf("*");
				else printf("-");
			}
			printf("\n");
		}
	}
	return 0;
}

