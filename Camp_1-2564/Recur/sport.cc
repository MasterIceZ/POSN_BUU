#include <stdio.h>

int n, a[333];

void simulate(int state, int win, int lose){
	if(win == n || lose == n){
		for(int i=1; i<=state; ++i){
			printf("%c ", a[i]);
		}
		printf("\n");
		return ;
	}
	a[state + 1] = 'W';
	simulate(state + 1, win + 1, lose);
	a[state + 1] = 'L';
	simulate(state + 1, win, lose + 1);
}

int main(){
	int w, l;
	scanf("%d %d %d", &n, &w, &l);
	simulate(0, w, l);
	return 0;
}
