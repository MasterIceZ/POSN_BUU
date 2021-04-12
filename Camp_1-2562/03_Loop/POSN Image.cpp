#include<stdio.h>
/*
		TASK: POSN Image
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
*/
int main (){
	int n,j,a,q;
	scanf("%d",&q);
	while(q--){
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	for(j = 1;j<=n-1;j++){
		if(j==1||i==1||i==(n+1)/2)
			printf("*");
			else
			printf("-");
		}
	for(a=1;a<=1;a++){
		if(i<=(n+1)/2)
		printf("*");
		else
		printf("-");
	}
	printf("-");
	for(j=1;j<=n;j++){
			if(i==1||j==1||j==n||i==n)
			printf("*");
			else
			printf("-");
		}
	printf("-");
	for(j=1;j<=n;j++){
		if(i==1||i==(n+1)/2||i==n){
			printf("*");
		}
		else if(i<(n+1)/2&&i>1&&j==1){
			printf("*");
		}
		else if(i>(n+1)/2&&i<n&&j==n){
			printf("*");
		}
		else{
			printf("-");
		}
		
	}
		printf("-");
	for(j=1;j<=n;j++){
		if(j==1||j==n||j==i)
		printf("*");
		else
		printf("-");
	}
		printf("\n");
	}
}
	
	return 0;
}
