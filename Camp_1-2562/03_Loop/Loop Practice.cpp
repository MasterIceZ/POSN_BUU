#include<stdio.h>
/*
		TASK: Loop Practice
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
*/
int main (){
	int a,i;
	scanf("%d",&a);
	for(i=1;i<=a;i++){
	printf("%d ",i);
}
	printf("\n");
	//int j=a;
	i=a;
	while(i>0){
		printf("%d ",i);
		i--;
	}
	printf("\n");
	i=1;
	//int k=2;
	do{
		if(i%2==0)
		printf("%d ",i);
		i++;
	}while(i<=a);
	//k =k-2;
	printf("\n");
	for(i=a;i>0;i--){
		if(i%2==0)
		printf("%d ",i);
	}
	printf("\n");
	i=1;
	while(i<=a){
		if(i%2==1)
		printf("%d ",i);
		i++;
	}
	printf("\n");
	i=a;
	do{
		if(i%2==1)
		printf("%d ",i);
		i--;
	}while(i>=1);
	return 0;
}
