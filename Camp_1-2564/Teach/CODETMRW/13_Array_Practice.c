#include<stdio.h>

int a[1100];
int main() {
	int n,k,cnt=0;
	scanf("%d", &n);
	for(int i=0; i<n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);
	for(int i=n-1; i>=0; i--) {
		printf("%d ", a[i]);
		if(a[i]==k) cnt++;
	}
	printf("\n%d\n", cnt);
	return 0;
}

