/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: 
 * EDITOR	: VsCode
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=2*n+1; ++i){
		for(int j=1; j<=2*n+1; ++j){
			if(i==1 || i==2*n+1 || j==1 || j==2*n+1){
				printf("*");
			}
			else if(i%2==1 && j<=i){
				printf("*");
			}
			else if(j%2==1 && i<=j){
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
