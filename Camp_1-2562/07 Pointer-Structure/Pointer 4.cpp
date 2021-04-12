#include<stdio.h>

int main (){
	int a=2;
	float b=3;
	int *p;
	float *p1;
	float sum;
	float *v;
	p = &a;
	p1 = &b;
	*v=*p+*p1;
	printf("%f",sum);
}
