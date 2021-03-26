#include<stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n*2+1;++i){
			for(int j=1;j<=n*2+1;++j){
				if(i == 1 || i == n*2+1 || j == 1 || j == n*2+1){
					printf("*");
				}
				else if(i % 2 == 1 && j <= i){
					printf("*");
				}
				else if(j % 2 == 1 && i <= j){
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
