#include<stdio.h>

int main (){
	int a;
	printf("Enter Number : ");
	scanf("%d",&a);
	if(a==0)
		printf("%d is Zero Number.",a);
	else if(a>0)
		printf("%d is Positive Number.",a);
	else 
		printf("%d is Negative Number.",a);
	return 0;
}
