#include<stdio.h>
#include<string.h>
int main (){
	char a[100];
	gets(a);
	int i,x=0,y=0,s=0;
	int len = strlen(a);
	for(i=0;i<len;i++){
		if(a[i]=='N'){
			if(s==0){
				printf("F");
			}
			else if(s==1){
				printf("RRRF");
				s = 0;
			}
			else if(s==2){
				printf("RRF");
				s = 0;
			}
			else if(s==3){
				printf("RF");
				s = 0;
			}
		}
		if(a[i]=='S'){
			if(s==0){
				printf("RRF");
				s = 2;
			}
			else if(s==1){
				printf("RF");
				s = 2;
			}
			else if(s==2){
				printf("F");
				s = 2;
			}
			else if(s==3){
				printf("RRRF");
				s = 2;
			}
		}
		if(a[i]=='E'){
			if(s==0){
				printf("RF");
				s = 1;
			}
			else if(s==1){
				printf("F");
			}
			else if(s==2){
				printf("RRRF");
				s = 1;
			}
			else if(s==3){
				printf("RRF");
				s = 1;
			}
		}
		if(a[i]=='W'){
			if(s==0){
				printf("RRRF");
				s = 3;
			}
			else if(s==1){
				printf("RRF");
				s = 3;
			}
			else if(s==2){
				printf("RF");
				s = 3;
			}
			else if(s==3){
				printf("F");
				s = 3;
			}
			
		}
		if(a[i]=='Z'){
			printf("Z");
			s = 0;
		}
	}
	return 0;
}
