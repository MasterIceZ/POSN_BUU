#include<stdio.h>
/*
		TASK: Roman Conversion
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
*/
int main (){
	int q,p;
	scanf("%d",&q);
	while(q>0){
		scanf("%d",&p);
		while(p>=1000){
			printf("M");
			p-=1000;
		}
		while(p>=900){
			printf("CM");
			p-=900;
		}
		while(p>=500){
			printf("D");
			p-=500;
		}
		while(p>=400){
			printf("CD");
			p-=400;
		}
		while(p>=100){
			printf("C");
			p-=100;
		}
		while(p>=90){
			printf("XC");
			p-=90;
		}
		while(p>=50){
			printf("L");
			p-=50;
		}
		while(p>=40){
			printf("XL");
			p-=40;
		}
		while(p>=10){
			printf("X");
			p-=10;
		}
		while(p>=9){
			printf("IX");
			p-=9;
		}
		while(p>=5){
			printf("V");
			p-=5;
		}
		while(p>=4){
			printf("IV");
			p-=4;
		}
		while(p>=1){
			printf("I");
			p-=1;
		}
		printf("\n");
		q--;
	}
	
	return 0;
}
