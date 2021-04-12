#include<stdio.h>

int main (){
	int a[24][24],i,j,r,c;
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d ",a[i][j]);
		}
	}
	printf("\n");
	for(i=r-1;i>=0;i--){
		for(j=c-1;j>=0;j--){
			printf("%d ",a[i][j]);
		}
	}
	printf("\n");
	for(j=0;j<c;j++){
		for(i=0;i<r;i++){
			printf("%d ",a[i][j]);
		}
	}
	printf("\n");
	for(j=c-1;j>=0;j--){
		for(i=r-1;i>=0;i--){
			printf("%d ",a[i][j]);
		}
	}
	return 0;
}
