/*
    TASK  : ArrayWalk
    AUTHOR: Hydrolyzed~
    GITHUB: MasterIceZ
    LANG  : C
    SCHOOL: RYW
*/

#include<stdio.h>

int a[33][33];

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
	for(int i=n-1;i>=0;--i){
		for(int j=m-1;j>=0;--j){
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
	for(int j=0;j<m;++j){
		for(int i=0;i<n;++i){
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
	for(int j=m-1;j>=0;--j){
		for(int i=n-1;i>=0;--i){
			printf("%d ", a[i][j]);
		}
	}
	return 0;
}
