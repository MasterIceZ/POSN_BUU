/*
    TASK  : 
    AUTHOR: Hydrolyzed~
    LANG  : C
    SCHOOL: RYW
*/

#include<stdio.h>

int main(){
	double a,b,c,d;
	scanf("%lf %lf %lf %lf", &a,&b,&c,&d);
	printf("%.2lf", ((a/(c-b))*d));	
	printf("\n");
	return 0;
}
