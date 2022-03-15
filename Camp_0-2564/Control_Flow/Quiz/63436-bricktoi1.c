#include <stdio.h>
#include <math.h>

int n, m, p[22], ok;
char a[22][22];

int main(){
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i){
		scanf(" %s", a[i] + 1);
	}
	for(int i=1; i<=m; ++i){
		scanf("%d", &p[i]);
	}
	for(int j=1; j<=m; ++j){
		ok = 0;
		for(int i=1; i<=n; ++i){
			if(a[i][j] == 'O' && !ok){
				int amt = 0, ii = i;
				while(1){
					if(ii - 1 < 1 || amt == p[j]){
						break;
					}
					a[ii - 1][j] = '#';
					ii--, amt++;
				}

				ok = 1;
				break;
			}
		}
		if(!ok){
			int amt = 0, ii = n + 1;
			while(1){
				if(ii - 1 < 1 || amt == p[j]){
					break;
				}
				a[ii - 1][j] = '#';
				ii--, amt++;
			}
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
