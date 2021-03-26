#include<stdio.h>

int main (){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d" , &n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i == 1 || j == 1 || i == n/2+1){
					printf("*");
				}
				else if(j == n && i <= n/2+1){
					printf("*");
				}
				else{
					printf("-");
				}
			}
			printf("-");
			for(int j=1;j<=n;++j){
				if(i == 1 || j == 1 || j == n || i == n){
					printf("*");
				}
				else{
					printf("-");
				}
			}
			printf("-");
			for(int j=1;j<=n;++j){
				if(i == n/2+1 || i == 1 || i == n){
					printf("*");
				}
				else if(j == 1 && i <= n/2+1){
					printf("*");
				}
				else if(j == n && i > n/2+1){
					printf("*");
				}
				else{
					printf("-");
				}
			}
			printf("-");
			for(int j=1;j<=n;++j){
				if(i == j || j == 1 || j == n){
					printf("*");
				}
				else{
					printf("-");
				}
			}

			printf("\n");
		}
	}
	return 0;
}
