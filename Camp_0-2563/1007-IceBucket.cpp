#include<stdio.h>
int main (){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m, cnt = 0;
		int player = 1;
		scanf("%d %d", &n, &m);
		while(n - player*100 > 0){
			n -= 10;
			player += m;
			player -= 1;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
