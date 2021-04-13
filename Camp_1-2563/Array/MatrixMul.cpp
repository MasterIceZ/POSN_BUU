/*
    TASK  :
    AUTHOR: Hydrolyzed~
    GITHUB: MasterIceZ
    LANG  : C
    SCHOOL: RYW
*/

#include<stdio.h>

int a[11][11], b[11][11], c[11][11];

int main(){
	int n, m, x, y;
	scanf("%d %d %d %d", &n, &m,&x,&y);	
	
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=0;i<x;++i){
		for(int j=0;j<y;++j){
			scanf("%d", &b[i][j]);
		}
	}
	if(m != x){
		printf("Can\'t Multiply.");
		return 0;
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<y;++j){
			for(int k=0;k<m;++k){
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<y;++j){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
