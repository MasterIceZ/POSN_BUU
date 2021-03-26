/*
    TASK  : Intro02 
    AUTHOR: Hydrolyzed~
    LANG  : C
    SCHOOL: RYW
*/

#include<stdio.h>
#include<ctype.h>

int main(){
	char a,b;
	scanf("%c %c", &a, &b);
	printf("%c ", isupper(a)?tolower(a):toupper(a));
	printf("%c", isupper(b)?tolower(b):toupper(b));
	printf("\n");
	return 0;
}
