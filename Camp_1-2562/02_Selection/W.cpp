#include<stdio.h>

int main (){
	double w;
	printf("Enter Weight : ");
	scanf("%lf",&w);
	if(w<1)
	printf("Small");
	else if (w>=1&&w<3)
	printf("Medium");
	else
	printf("Large");
	return 0;
}
