#include<stdio.h>
#include<conio.h>
#include<string.h>

int main (){
	struct profile{
		char name[20];
		int age;
	}s[10];
	for(int i=0;i<10;i++){
		printf("Student[%d]\n",i);
		printf("\t %s",s[i].name);
		printf("\t age");
		scanf("%d",&s[i].age);
	}
	for(int j=0;j<10;j++)
		if(s[j].age>20)
			printf("\n%s,%d",s[j].name,s[j].age);
	return 0;
}
