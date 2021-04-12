#include<stdio.h>

int main (){
	int a,i;
	scanf("%d",&a);
	int num[a];
		for(i=0;i<a;i++){
			scanf("%d",&num[i]);
		}
		for(i=2;i<=a;i++){
				if(num[i]<num[i-1])
					printf("%d ",num[i]);
				if()
		}
	
	return 0;
}
