#include<stdio.h>

int main () {
	int num;
	int fac=0;
	printf("Enter Number : ");
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		if(num%i==0){
			printf("%d can divide %d\n",i,num);
			fac++;
		}
	}
	printf("%d has %d factors\n",num,fac);
	if(fac==2){
		printf("%d is a prime number",num);
	}
}
