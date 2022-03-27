#include<stdio.h>
#include<math.h>

int main() {
	int n;
	scanf("%d", &n);
	int sq = sqrt(n), cnt=0;
	for(int i=1; i<=sq; i++) {
		if(n%i==0) cnt++;
	}
	if(n==1) printf("No\n");
	else if(cnt==1) printf("Yes\n");
	else printf("No\n");
	return 0;
}
