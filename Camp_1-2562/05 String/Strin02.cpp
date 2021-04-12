#include<stdio.h>
#include<string.h>
int main (){
	char pass[20];
	int i,c=0;
	gets(pass);
	for(i=0;i<strlen(pass);i++){
		if(pass[i]>='0'&&pass[i]<='9')
		c++;
	}
	if(c>0){
		printf("OK");
	}
	else{
		printf("Try Again");
	}
	return 0;
}
