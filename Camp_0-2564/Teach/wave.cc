#include <stdio.h>
#include <string.h>

char a[555][555];

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		int n;
		scanf("%d", &n);
		n = 4 * n - 3;
		int i = 1, j = 1, check;
		memset(a, '.', sizeof a);
		a[1][1] = '#';
		while(1){
			check = 0;
			while(j + 1 <= n && a[i][j + 2] != '#'){
				a[i][++j] = '#';
				check = 1;
			}
			while(i + 1 <= n && a[i + 2][j] != '#'){
				a[++i][j] = '#';
				check = 1;
			}
			while(j - 1 >= 1 && a[i][j - 2] != '#'){
				a[i][--j] = '#';
				check = 1;
			}
			while(i - 1 >= 1 && a[i - 2][j] != '#'){
				a[--i][j] = '#';
				check = 1;
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
	}
	return 0;
}
