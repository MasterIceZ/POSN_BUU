/*
    TASK 	:	62_Sphere 
    AUTHOR	: Hydrolyzed~
    LANG  	: C
    SCHOOL	: RYW
*/

#include<stdio.h>
#include<math.h>
int main(){
	double a;
	scanf("%lf", &a);
	printf("%.3lf\n", 4 * acos(-1) * a * a);	
	printf("%.3lf\n", 4 * acos(-1) * a * a * a / 3);
	printf("%.3lf\n", acos(-1) * a * a);	
	printf("%.3lf\n", acos(-1) * 2 * a);	
	printf("\n");
	return 0;
}
