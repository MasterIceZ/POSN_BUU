#include<stdio.h>

int main (){
	int a[5];
	int b[10];
	int i,c=0,j;
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}	
	for(i=0;i<10;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<5;i++){
		for(j=0;j<10;j++){
			if(a[i]==b[j]){
			c++;	
			}
		}
	}
	if(c==5){
		printf("Subset");
	}
	else
		printf("Not Subset");
	return 0;
}
