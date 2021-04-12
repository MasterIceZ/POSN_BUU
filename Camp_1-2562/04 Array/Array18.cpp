#include<stdio.h>

int main (){
	int a[5][5];
	int i,j,sum=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&a[i][j]);
			if(i=j){
				sum+=a[i][j];
			}
		}
	}
	printf("%d",sum);
	return 0;
}
