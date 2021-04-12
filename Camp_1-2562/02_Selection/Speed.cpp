#include<stdio.h>

int main (){
	double speed;
	scanf("%lf",&speed);
	if(speed<=90)
	printf("Normal");
	else if(speed<=120)
	printf("Warning");
	else
	printf("Dangerous");
	return 0;
}
