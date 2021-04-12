#include<stdio.h>
int main () {
	int star,back;
	printf("Enter Number : ");
	scanf("%d",&back);
	for(int i=1;i<=back;i++){
		for(star=back;star>=i;star--){
			printf("*");
		}
		printf("\n");
	}
}
