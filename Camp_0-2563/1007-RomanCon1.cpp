#include<stdio.h>

int main (){
	int q;
	scanf("%d", &q);
	while(q--){
		int a;
		scanf("%d", &a);
		for(; a>=1000;a-=1000){
			printf("M");
		}
		for(; a>=900;a-=900){
			printf("CM");
		}
		for(; a>=500;a-=500){
			printf("D");
		}
		for(; a>=400;a-=400){
			printf("CD");
		}
		for(; a>=100;a-=100){
			printf("C");
		}
		for(; a>=90;a-=90){
			printf("XC");
		}
		for(; a>=50;a-=50){
			printf("L");
		}
		for(; a>=40;a-=40){
			printf("XL");
		}
		for(; a>=10;a-=10){
			printf("X");
		}
		for(; a>=9; a-= 9){
			printf("IX");
		}
		for(; a>=5;a-=5){
			printf("V");
		}
		for(; a>=4;a-=4){
			printf("IV");
		}
		for(;a>=1;--a){
			printf("I");
		}
		printf("\n");
	}
	return 0;
}
