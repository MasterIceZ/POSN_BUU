#include<stdio.h>
#include<string.h>
	//Array
int main (){
	int score[5];
	int sum = 0;
	for(int i=0;i<5;i++){
		scanf("%d",&score[i]);
		sum = sum + score[i];
	}
	printf("%d",sum);
	return 0;
}
