#include<stdio.h>

int main (){
	int i;
	printf("Enter number between 1 and 3 : ");
	scanf("%d",&i);
	switch(i) {
		case 1:
			printf("One\n");
			break;
		case 2:
			printf("Two\n");
			break;
		case 3:
			printf("Three\n");
			break;
		default:
			printf("Unknown!!\n");
	}
	return 0;
}
