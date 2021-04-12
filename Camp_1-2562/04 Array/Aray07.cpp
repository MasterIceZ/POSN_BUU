#include<stdio.h>
#include<math.h>

int main (){
	int r[10],i;
	double a[10];
	for(i=0;i<10;i++){
		scanf("%d",&r[i]);
		a[i] = M_PI*pow(r[i],2);
	}
	for(i=0;i<10;i++){
		printf("%.2lf\n",a[i]);
	}
	return 0;
}
