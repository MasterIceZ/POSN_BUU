#include<stdio.h>
/*
		TASK: intro01
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
*/
int main(){
	int s;
	scanf("%d",&s);
	if(s>=80&&s<=100)
	printf("A");
	else if(s>=75&&s<=79)
	printf("B+");
	else if(s>=70&&s<=74)
	printf("B");
	else if(s>=65&&s<=69)
	printf("C+");
	else if(s>=60&&s<=64)
	printf("C");
	else if(s>=55&&s<=59)
	printf("D+");
	else if(s>=50&&s<=54)
	printf("D");
	else
	printf("F");
}
