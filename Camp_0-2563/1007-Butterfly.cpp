/*
    TASK  :
    AUTHOR: Hydrolyzed~
    GITHUB: MasterIceZ
    LANG  : C
    SCHOOL: RYW
*/

#include<stdio.h>

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(j <= i){
				printf("*");
			}
			else{
				printf("-");
			}
		}
		for(j=2;j<=n;++j){
			if(n-j >= i){
				printf("-");
			}
			else{
				printf("*");
			}
		}
		printf("\n");
	}
	for(i=2;i<=n;++i){
		for(j=1;j<=n;++j){
			if(n - j + 1>= i){
				printf("*");
			}
			else{
				printf("-");
			}
		}
		for(j=2;j<=n;++j){
			if(j+1 <= i){
				printf("-");
			}
			else{
				printf("*");
			}
		}
		printf("\n");
	}
	//printf("\n");
	return 0;
}
