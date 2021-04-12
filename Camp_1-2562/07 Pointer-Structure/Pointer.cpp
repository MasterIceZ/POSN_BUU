#include<stdio.h>

int main ()
{
	int age=25;
	int *ptr = &age;
	printf("%p",ptr);
	return 0;
}
