#include<stdio.h>
#include<math.h>
/*
		TASK: Pythagoras
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
*/
int main(){
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(a==0)
	printf("%.2lf",sqrt(pow(c,2)-pow(b,2)));
	if(b==0)
	printf("%.2lf",sqrt(pow(c,2)-pow(a,2)));
	if(c==0)
	printf("%.2lf",sqrt(pow(a,2)+pow(b,2)));
	
}
