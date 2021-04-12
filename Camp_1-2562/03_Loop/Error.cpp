#include<stdio.h>
int main (){
	int i=1,sum=0,a;
	while(i<11){
		scanf("%d",&a);
		if(a<1){
			sum = -999;
			break;
		}
		sum = a + sum;
		i++;
	}
	if(sum=-999){
		printf("Error");
	}
	else
	printf("%d",sum);
	return 0;
}
