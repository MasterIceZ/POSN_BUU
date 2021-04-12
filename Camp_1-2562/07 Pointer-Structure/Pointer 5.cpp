#include<stdio.h>

int main (){
	int mynum[5]={10,20,30,40,50};
	int *mypoint;
	mypoint = mynum;
	*mypoint = 20;
	mypoint++;
	*mypoint = 80;
	mypoint = mynum;
	mypoint += 4;
	*mypoint =100;
	printf("%d",*mypoint);
}
