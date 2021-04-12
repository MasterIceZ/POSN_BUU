#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main () {

	srand(time(NULL));
	int v = rand()%5;
	int a = v++;
	printf("%d",a);
	

}
