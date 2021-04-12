#include<stdio.h>
int main (){
	int a=0;
	int sum=0;
	do{
		sum=a+sum;
		a++;	
	}while(a<=5);
	printf("%d",sum);
	return 0;
}
