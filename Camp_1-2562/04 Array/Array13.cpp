#include<stdio.h>

int main (){
	int num[5],i,h;
	for(i=0;i<5;i++){
		scanf("%d",&num[i]);	
	}
	int g;
	scanf("%d",&g);
	
		for(i = 0;i<5;i++){
		if(g == num[i]){
			h = i;
			break;
		}
	}
	if(h!=0)
	printf("Found at position : %d",h);
	else
	printf("Not found");
	return 0;
}
