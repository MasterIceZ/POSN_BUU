#include<stdio.h>

int main () {
	int num1 ;
	int num2 ;
	int num3 ;
	printf("Enter Number [1] : \n");
	scanf("%d",&num1);
	printf("Enter Number [2] : \n");
	scanf("%d",&num2);
	printf("Enter Number [3] : \n");
	scanf("%d",&num3);
	int sum = num1 + num2 + num3;
	float bar = sum/3;
	printf("Average Number is %2f",bar);
}
