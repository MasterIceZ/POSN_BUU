#include<stdio.h>

int main (){
	int num[12],i;
	for(i=0;i<12;i++){
		scanf("%d",&num[i]);
		num[i] = (num[i]%100)/10;
	}
	for(i=0;i<12;i++){
		printf("%d ",num[i]);
	}
	return 0;
}
