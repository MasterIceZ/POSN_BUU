#include <stdio.h>
#include <stdlib.h>

int n, r, k, cnt;
int a[15];

void simulate(int state, int last){
	if(state == r){
		cnt++;
		if(cnt != k){
			return ;
		}
		for(int i=0; i<r; ++i){
			printf("%d ", a[i]);
		}
		printf("\n");
		exit(0);
	}
	for(int i=last + 1; i<=n; ++i){
		a[state] = i;
		simulate(state + 1, i);
	}
}

int main(){
	scanf("%d %d %d", &n, &r, &k);
	simulate(0, 0);
	return 0;
}
