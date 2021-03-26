/*
    TASK  : 
    AUTHOR: Hydrolyzed~
    LANG  : C
    SCHOOL: RYW
*/

#include<stdio.h>
#include<math.h>

int main(){
	double x1,x2,x3,y1,y2,y3,k;
	scanf("%lf %lf %lf %lf %lf %lf %lf", &x1,&y1,&x2,&y2,&x3,&y3,&k);
	double a = sqrt(pow(x1-x2,2) + pow(y1-y2, 2));
	double b = sqrt(pow(x1-x3,2) + pow(y1-y3, 2));
	double c = sqrt(pow(x2-x3,2) + pow(y2-y3, 2));
	double s = a+b+c;
	s/=2;
	printf("%.2lf", sqrt(s*(s-a)*(s-b)*(s-c)));
	double ans = acos(-1)*k*k + a*k + b*k + c*k;
	printf("\n%.2lf", ans);
	printf("\n");
	return 0;
}
