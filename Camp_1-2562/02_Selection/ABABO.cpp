#include<stdio.h>
#include<ctype.h>
 
int main (){
	char blood1,blood2;
	scanf("%c%c",&blood1,&blood2);
	blood1 = toupper(blood1);
	blood2 = toupper(blood2);
	if(blood1=='A'||blood1=='a')
		if(blood2=='B')
		printf("Rational,Versatile,Discriminating");
		else   
		printf("Serious,Earnest,Tidy,Fastidious");
	else if(blood1=='O')
		printf("Rough,Workaholic,Rude,Sociable");
	else if(blood1=='B')
		printf("Optimistic,Curious,Irresponsible");
	else 
		printf("Error");
	
	return 0;
}
