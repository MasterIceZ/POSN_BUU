#include<stdio.h>

int main (){
	int i,a[5],j;
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++){
		printf("Day %d : ",i+1);
		for(j=0;j<a[i];j++){
			printf("*");
		}
		printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
