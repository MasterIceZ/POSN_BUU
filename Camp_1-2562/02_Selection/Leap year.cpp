#include<stdio.h>

int main (){
	int year;
	printf("Enter Year : ");
	scanf("%d",&year);
	if(year>2100)
		if((year-543)%4==0)
		printf("%d is leap a year",year);
		else
		printf("%d is not a leap year",year);
	else if(year%4==0)
		printf("%d is leap a year",year);
	else
		printf("%d is not a leap year",year);
	return 0;
}
