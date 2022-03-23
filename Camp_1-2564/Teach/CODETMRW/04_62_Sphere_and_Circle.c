#include<stdio.h>
#include<math.h>
int main() {
	double r;
	scanf("%lf", &r);
	printf("%.3lf\n", acos(-1)*4*r*r);
	printf("%.3lf\n", 4.0/3*acos(-1)*r*r*r);
	printf("%.3lf\n", acos(-1)*r*r);
	printf("%.3lf\n", acos(-1)*2*r);
	return 0;
}

