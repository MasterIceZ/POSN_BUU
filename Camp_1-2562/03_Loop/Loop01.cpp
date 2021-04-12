#include<stdio.h>
int main (){
	int a=0,b=1;
	while(b<=5){
		a=b+a;
		b++;
	}
	printf("%d",a);
	return 0;
}
