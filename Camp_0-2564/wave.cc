#include <stdio.h>
#include <string.h>

char a[555][555];

void solve(){
	int n;
	memset(a, '.', sizeof a);
	scanf("%d", &n);
	n = 4 * n - 3;
	int i = 1, j = 1;
	a[1][1] = '#';
	int check;
	while(1){
		check = 0;
		while(j + 1 <= n && a[i][j + 2] != '#'){
			check = 1;
			a[i][++j] = '#';
		}
		while(i + 1 <= n && a[i + 2][j] != '#'){
			a[++i][j] = '#';
		}
		while(j - 1 >= 1 && a[i][j - 2] != '#'){
			a[i][--j] = '#';
		}
		while(i - 1 >= 1 && a[i - 2][j] != '#'){
			a[--i][j] = '#';
		}
		if(!check){
			break;
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return ;
}

int main(){
	int q = 1;
	scanf("%d", &q);
	while(q--){
		solve();
	}
	return 0;
}
