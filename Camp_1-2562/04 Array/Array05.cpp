#include<stdio.h>

int main (){
	int num[5],i,q,a=0;
	for(i=0;i<5;i++){
		scanf("%d",&num[i]);
	}
	scanf("%d",&q);
	for(i = 0;i<5;i++){
		if(q = num[i]){
			a++;
		}
	}
	if(a>0)
	printf("Found it.");
	else
	printf("Not found.");
	return 0;
}
