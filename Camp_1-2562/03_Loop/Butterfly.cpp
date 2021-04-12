#include<stdio.h>
/*
		TASK: Butterfly
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
*/
int main (){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		for(j=0;j<=i;j++){
			printf("*");
		}
		for(j=0;j<2*n-3-2*i;j++){
			printf("-");
		}
		for(j=0;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	for(i=0;i<2*n-1;i++){
		printf("*");
	}
	printf("\n");
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			printf("*");
		}
		
		for(j=0;j<2*i+1;j++){
			printf("-");
		}
		for(j=0;j<n-1-i;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
