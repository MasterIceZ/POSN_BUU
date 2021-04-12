#include<stdio.h>
#include<math.h>

int main(){
	double a,b,c,d;
	scanf("%lf",&a);
	scanf("%lf",&b);
	scanf("%lf",&c);
	d = sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(c*M_PI/180));
	printf("c = %.2lfcm",d);
}
