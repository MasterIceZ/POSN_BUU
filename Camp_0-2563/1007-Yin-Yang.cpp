#include<bits/stdc++.h>
using namespace std;

int main (){
	int t;
	scanf("%d", &t);
	while(t--){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n+2;++i){
		for(int j=1;j<=n+2;++j){
			if(n - i >= j - 2){
				printf(".");
			}
			else{
				printf("#");
			}
		}
		for(int j=1;j<=n+2;++j){
			if(i==1 || j==1 || i == n+2 || j == n+2){
				printf("+");
			}
			else{
				printf("#");
			}
		}
		printf("\n");
	}
	for(int i=1;i<=n+2;++i){
		for(int j=1;j<=n+2;++j){
			if(i == 1 || j == 1 || i == n+2 || j == n+2){
				printf("#");
			}
			else{
				printf("+");
			}
		}
		for(int j=1;j<=n+2;++j){
			if(n-i >= j-3){
				printf("+");
			}
			else{
				printf(".");
			}
		}
		printf("\n");
	}
	}
	return 0;
}
