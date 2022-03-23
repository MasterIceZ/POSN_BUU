#include<stdio.h>
#include<stdlib.h>

int n,r,k,cnt=0;
int a[20];
void combi(int now, int last) {
	if(now == r) {
		++cnt;
		if(cnt==k) {
			for(int i=0; i<r; i++)
				printf("%d ", a[i]);
			printf("\n");
			exit(0);
		}
		return;
	}
	for(int i=last+1; i<=n; i++) {
		a[now] = i;
		combi(now+1, i);
	}
}
int main() {
	scanf("%d %d %d", &n, &r, &k);
	combi(0, 0);
	return 0;
}

