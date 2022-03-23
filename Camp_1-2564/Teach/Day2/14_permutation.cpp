#include<stdio.h>
#include<stdlib.h>

int n,r,k,cnt=0;
int a[15], mk[15];
void permu(int now) {
	if(now==r) {
		++cnt;
		if(cnt == k) {
			for(int i=0; i<r; i++)
				printf("%d ", a[i]);
			printf("\n");
			exit(0);
		}
		return;
	}
	for(int i=1; i<=n; i++) {
		if(mk[i]) continue;
		mk[i] = 1;
		a[now] = i;
		permu(now+1);
		mk[i] = 0;
	}
}
int main() {
	scanf("%d %d %d", &n, &r, &k);
	permu(0);
	return 0;
}
