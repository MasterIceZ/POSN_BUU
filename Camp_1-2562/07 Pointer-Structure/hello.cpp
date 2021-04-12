#include<stdio.h>

int main (){
	int a[10]={2,3,5,7,11,13,17,19,23,0};
	int  *ptr,i;
	ptr = &a[0];
	int sum=0;
	for(i=0;i<10;i++){
		sum += *ptr; 
		ptr++;
	}
	printf("%s",*ptr);
}
