#include<stdio.h>

int main (){
	int a[7],i,b[7],c[7],sum=0;
	for(i=0;i<7;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<7;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<7;i++){
		scanf("%d",&c[i]);
	}
	for(i=0;i<7;i++){
		sum = a[i]+b[i]+c[i];
		printf("%d ",sum); 
	}
	
	return 0;
}
