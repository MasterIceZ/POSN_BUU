/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: POSN Image
 * EDITOR	: VsCode
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i == 1 || j == 1 || i == n/2+1){
				printf("*");
			}
			else if(j==n && i<=n/2+1){
				printf("*");
			}
			else{
				printf("-");
			}
		}
		printf("-");
		for(int j=1; j<=n; ++j){
			if(i==1 || j==1 || i==n || j==n){
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
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int i=1; i<=t; ++i){
//		cout << "Case #" << i << ": ";
		solution();
//		cout << endl;
	}
	return 0;
}
