#include<stdio.h>

int main (){
	int i,a[5],j;
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
		for(j=0;j<12;j++){
			printf("%d x %d = %d\n",a[i],j+1,a[i]*(j+1));
		}
		printf("\n");
	}
	return 0;
}
