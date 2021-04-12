#include<stdio.h>

int main (){
	int num[10],i,c=0;
	for(i=0;i<10;i++){
		scanf("%d",&num[i]);
		if(num[i]%10==7){
			c++;
		}
	}
	printf("%d",c);
	return 0;
}
