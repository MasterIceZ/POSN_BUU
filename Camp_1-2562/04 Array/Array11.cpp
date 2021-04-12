#include<stdio.h>

int main (){
	char a[5];
	int i,b[5];
	for(i=0;i<5;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<5;i++){
		scanf(" %c",&a[i]);
	}
	for(i=0;i<5;i++){
		printf("%d%c\n",b[i],a[i]);
	}
	return 0;
}
