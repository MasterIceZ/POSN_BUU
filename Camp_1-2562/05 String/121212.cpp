#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void printhead(int h){
	int i;
	for(i=0;i<h;i++){
		printf("*");
	}
}
void printbody(int h,int b){
	int i,j;
	for(i=0;i<b;i++){
	printf("*");
		for(j=0;j<h-2;j++){	
		printf(" ");
		}
	printf("*\n");
		}
	}
int main (){
	int head;
	int body;
	scanf("%d",&head);
	scanf("%d",&body);
	printhead(head);
	printf("\n");
	printbody(head,body);
		printhead(head);

	return 0;
}
