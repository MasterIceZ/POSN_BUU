#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			printf("%c", j<=i ? '*': '-');
		}
		for(int j=2; j<=n; ++j){
			printf("%c", n-j>=i ? '-': '*');
		}
		printf("\n");
	}
	for(int i=2; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			printf("%c", n-j+1>=i ? '*': '-');
		}
		for(int j=2; j<=n; ++j){
			printf("%c", j+1<=i ? '-': '*');
		}
		printf("\n");
	}
}
