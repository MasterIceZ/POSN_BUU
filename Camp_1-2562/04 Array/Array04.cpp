#include<stdio.h>

int main (){
	double a[5],s;
	int i;
	scanf("%lf",&s);
	for(i=0;i<5;i++){
		scanf("%lf",&a[i]);
	}
	for(i = 0;i<5;i++){
		if(a[i]>=s){
			printf("%.2lf ",a[i]);
		}
	}
	return 0;
}
