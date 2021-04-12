#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//string
int main (){
	char a[100];
	char b[100];
	gets(a);
	gets(b);
	int c = strlen(a);
	int d = strlen(b);
	int e;
	if(c>d){
		printf("%s",c);
		e = c-d;
	}
	else{	
	printf("%s",d);
	e = d-c;
	}
	
	printf("%d",e);
	return 0;
}
