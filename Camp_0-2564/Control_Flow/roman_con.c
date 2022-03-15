#include <stdio.h>

void solve(){
	int n;
	scanf("%d", &n);
	for(; n>=1000; n-=1000){
		printf("M");
	}
	for(; n>=900; n-=900){
		printf("CM");
	}
	for(; n>=500; n-=500){
		printf("D");
	}
	for(; n>=400; n-=400){
		printf("CD");
	}
	for(; n>=100; n-=100){
		printf("C");
	}
	for(; n>=90; n-=90){
		printf("XC");
	}
	for(; n>=50; n-=50){
		printf("L");
	}
	for(; n>=40; n-=40){
		printf("XL");
	}
	for(; n>=10; n-=10){
		printf("X");
	}
	for(; n>=9; n-=9){
		printf("IX");
	}
	for(; n>=5; n-=5){
		printf("V");
	}
	for(; n>=4; n-=4){
		printf("IV");
	}
	for(; n>=1; n-=1){
		printf("I");
	}
}

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		solve();
		printf("\n");
	}
	return 0;
}
