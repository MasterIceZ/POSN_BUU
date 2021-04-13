/*
    TASK  :
    AUTHOR: Hydrolyzed~
    GITHUB: MasterIceZ
    LANG  : C
    SCHOOL: RYW
*/

#include<stdio.h>

int n, m;
char a[33][33];
int p[33];

void rec(int i, int j, int state){
	if(state == p[j]){
		return ;
	}
	if(i-1>=0){
		a[i-1][j] = '#';
		rec(i-1, j, state+1);
	}
	else{
		return ;
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf(" %c", &a[i][j]);
		}
	}

	for(int i=0;i<m;++i){
		scanf("%d", &p[i]);
	}
	int check = 0;
	for(int j=0; j<m; ++j){
		check = 0;
		for(int i=0;i<n;++i){
			if(check !=0){
				continue;
			}
			if(a[i][j] == 'O'){
				rec(i,j,0);
				check = 1;
			}
		}
		if(check == 0){
			rec(n, j, 0);
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
