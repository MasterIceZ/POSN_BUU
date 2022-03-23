#include <stdio.h>
int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				if(j == 1 || i == 1){
					printf("*");
				}
				else if(i == n / 2 + 1){
					printf("*");
				}
				else if(j == n && i <= n / 2 + 1){
					printf("*");
				}
				else{
					printf("-");
				}
			}
			printf("-");
			for(int j=1; j<=n; ++j){
				if(i == 1 || j == 1 || i == n || j == n){
					printf("*");
				}
				else{
					printf("-");
				}
			}
			printf("-");
			for(int j=1; j<=n; ++j){
				if(i == 1 || i == n){
					printf("*");
				}	
				else if(i == n / 2 + 1){
					printf("*");
				}
				else if(j == 1 && i <= n / 2 + 1){
					printf("*");
				}
				else if(j == n && i >= n / 2 + 1){
					printf("*");
				}
				else{
					printf("-");
				}
			}
			printf("-");
			for(int j=1; j<=n; ++j){
				if(j == 1 || j == n){
					printf("*");
				}
				else if(i == j){
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
