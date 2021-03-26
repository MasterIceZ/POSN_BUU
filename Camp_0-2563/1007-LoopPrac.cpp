#include<stdio.h>
#include<math.h>
int main (){
	int a;
	scanf("%d", &a);
	for(int i=1;i<=a;++i){
		printf("%d ", i);
	}
	printf("\n");
	int it = a;
	while(it>0){
		printf("%d ",it);
		it--;
	}
	printf("\n");
	it=1;
	do{
		if(it%2==0){
			printf("%d ",it);
		}
		it++;
	}while(it <= a);
	printf("\n");
	for(int i=a;i>0;--i){
		if(i%2==0){
			printf("%d ", i);
		}
	}
	printf("\n");
	it = 1;
	while(it<=a){
		if(it%2==1){
			printf("%d ",it);
		}
		it++;
	}
	printf("\n");
	it = a;
	do{
		if(it%2==1){
			printf("%d ", it);
		}
		it--;
	}while(it>=1);
	return 0;
}
