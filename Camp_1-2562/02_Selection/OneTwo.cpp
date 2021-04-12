#include<stdio.h>

int main (){
	int num;
	printf("Enter an integer :");
	scanf("%d",&num);
	if(num%10==0)
	printf("Zero");
	else if(num%10==1)
	printf("One");
	else if(num%10==2)
	printf("Two");
	else if(num%10==3)
	printf("Three");
	else if(num%10==4)
	printf("Four");
	else if(num%10==5)
	printf("Five");
	else if(num%10==6)
	printf("Six");
	else if(num%10==7)
	printf("Seven");
	else if(num%10==8)
	printf("Eight");
	else
	printf("Nine");
	return 0;
}
