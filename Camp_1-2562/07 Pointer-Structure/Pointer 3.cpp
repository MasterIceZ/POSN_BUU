#include<stdio.h>

int main (){
	int a=2;
	float b = 3;
	char word[]="Pointer is very hard for me";
	int c[5]={5,6,7,8,9};
	int *w ;
	w= &a;
	float *x ;
	x= &b;
	char *y ;
	y= word;
	int *z ;
	z= c;
	printf("%p\n",w);
	printf("%p\n",x);
	printf("%p\n",y);
	printf("%p\n",z);
	return 0;
}
