#include<stdio.h>
int main () {
	int i,A[i];
	int b = 0;
	printf("How many number are you going to type : ");
	scanf("%d",&i);
	for(int a=1;a<=i;a++){
		printf("Enter Number %d : ",a);
		scanf("%d",&A[i]);
		b = A[i] + b;
	}
	printf("%d",b);
}
